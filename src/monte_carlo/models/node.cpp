#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>
#include <monte_carlo/models/rollout_strategy_interface.h>
#include <monte_carlo/factories/tree_factory_interface.h>
#include <cmath>
#include <utility>
#include <sstream> // For stringstream to format UCB logs
#include <limits>  // For std::numeric_limits
#include <format>  // Added for std::format

using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::factories::TreeFactoryBase;
using std::string;
using std::shared_ptr;
using std::vector;
using sophia::logging::logger_ptr; // Added using directive

Node::Node(string name, const logger_ptr& logger)
    : m_name_(std::move(name))
    , m_logger_(logger)
{
    if (m_logger_) m_logger_->debug("Node created: {}", m_name_);
}

void Node::SetParent(const std::shared_ptr<Action>& action)
{
    m_parent_action_ = action;
}

std::shared_ptr<Action> Node::SelectBestAction() const
{
    if (m_child_action_.empty())
    {
        if (m_logger_) m_logger_->warn("Node '{}' has no children to select best action from.", Name());
        return nullptr;
    }

    double best_score = 0; // UCB scores are non-negative, so -1.0 is safe.
    shared_ptr<Action> best_child = nullptr;

    if (m_logger_)
    {
        std::stringstream ss;
        ss << "  Node '" << Name() << "' - Candidate Actions UCB scores (c=2):" << std::endl;
        for (const auto& child : m_child_action_)
        {
            const double current_score = child->UpperConfidenceBound(2);
            if (auto target = child->Target())
            {
                ss << "    - Action leading to '" << target->Name()
                   << std::format("(T:{:.4f} N:{}) UCB: {:.4f}", target->TotalReward(), target->VisitCount(), current_score) << std::endl;
            } else {
                 ss << "    - Action leading to (nullptr) UCB: " << std::format("{:.4f}", current_score) << std::endl;
            }
        }
        m_logger_->debug("{}", ss.str());
    }

    for (const auto& child : m_child_action_)
    {
        const double current_score = child->UpperConfidenceBound(2);
        if (best_child == nullptr || current_score > best_score)
        {
            best_score = current_score;
            best_child = child;
        }
    }
    if (m_logger_ && best_child && best_child->Target()) m_logger_->debug("  Node '{}' selected action leading to '{}' with UCB score: {:.4f}", Name(), best_child->Target()->Name(), best_score);
    return best_child;
}

shared_ptr<Node> Node::Expand()
{
    const vector<shared_ptr<Action>> child_actions = this->GetAvailableActions();
    if (child_actions.empty())
    {
        if (m_logger_) m_logger_->info("  Node '{}' has no available actions to expand.", Name());
        return nullptr;
    }

    // Add all available actions as children
    for(const auto& child : child_actions)
    {
        child->Generate(); // Generate the target node if not already
        auto target = child->Target();
        if (target) {
            if (m_logger_) m_logger_->debug("  Node '{}' adding child action leading to '{}'", Name(), target->Name());
            m_child_action_.push_back(child);
            target->SetParent(child);
        } else {
            if (m_logger_) m_logger_->error("  Node '{}' generated a null target for action '{}'", Name(), child->Name());
        }
    }

    // After adding all, we can return the first child's target node for simulation
    // This is typical for an immediate rollout after expansion.
    if (!m_child_action_.empty()) {
        if (m_logger_ && m_child_action_.front()->Target()) m_logger_->debug("  Node '{}' expanded. First new child is '{}'", Name(), m_child_action_.front()->Target()->Name());
        return m_child_action_.front()->Target();
    }
    
    return nullptr; // Should not happen if child_actions was not empty and generated targets
}


double Node::Rollout()
{
    if (this->IsTerminalState())
    {
        if (m_logger_) m_logger_->debug("  Rollout: Node '{}' is terminal. Value: {:.4f}", Name(), this->Value());
        return this->Value();
    }

    auto select_strategy = RolloutStrategy();
    if (!select_strategy)
    {
        if (m_logger_) m_logger_->error("No rollout strategy available for node '{}'", Name());
        return 0.0; // Or throw, depending on error handling policy
    }

    vector<shared_ptr<Action>> actions_for_rollout;
    // In rollout, we should typically consider all possible actions, not just sampled children
    actions_for_rollout = this->GetAvailableActions();

    if (actions_for_rollout.empty())
    {
        if (m_logger_) m_logger_->warn("  Rollout: Node '{}' has no available actions during simulation. Returning 0.0.", Name());
        return 0.0; // If no moves, then game might be blocked or draw.
    }

    if (const auto selected_action = select_strategy->select_action(actions_for_rollout))
    {
        selected_action->Generate(); // Ensure the target node exists
        if (auto new_node = selected_action->Target())
        {
            if (m_logger_) m_logger_->debug("  Rollout: Node '{}' selecting action leading to '{}'", Name(), new_node->Name());
            return new_node->Rollout();
        }
        else
        {
            if (m_logger_) m_logger_->error("  Rollout: Action '{}' generated a null target node.", selected_action->Name());
            return 0.0;
        }
    }
    else
    {
        if (m_logger_) m_logger_->warn("  Rollout: Rollout strategy failed to select an action from node '{}'. Returning 0.0.", Name());
        return 0.0;
    }
}

void Node::Backpropagate(const double reward)
{
    if (m_visit_count_ + 1 == 0) // Check for overflow before incrementing (unsigned long max + 1 = 0)
    {
        if (m_logger_) m_logger_->error("Visit count overflow detected for node '{}'", Name());
        throw std::runtime_error("Node::Backpropagate - visit count overflow");
    }

    // Check for double overflow/underflow
    if ((reward > 0 && m_total_reward_ > std::numeric_limits<double>::max() - reward) ||
        (reward < 0 && m_total_reward_ < std::numeric_limits<double>::lowest() - reward))
    {
        if (m_logger_) m_logger_->error("Total reward overflow/underflow detected for node '{}'", Name());
        throw std::runtime_error("Node::Backpropagate - total reward overflow");
    }

    m_total_reward_ += reward;
    m_visit_count_++;

    if (m_logger_) m_logger_->debug("  Backpropagating on '{}'. New Total Reward: {:.4f}, New Visit Count: {}", Name(), m_total_reward_, m_visit_count_);

    if (const auto sp = m_parent_action_.lock())
    {
        if(auto parent_node = sp->Source())
        {
            parent_node->Backpropagate(reward);
        }
    }
}

std::string Node::Name() const
{
    return m_name_;
}

double Node::UpperConfidenceBound(const int c) const
{
    // If not visited, UCB is infinity to prioritize exploration
    if (m_visit_count_ == 0)
    {
        return std::numeric_limits<double>::infinity();
    }

    // Need parent's visit count for UCB calculation
    shared_ptr<Node> parent_node = nullptr;
    if (const auto sp = m_parent_action_.lock())
    {
        parent_node = sp->Source();
    }

    // If no parent or parent visit count is 0, UCB formula is not applicable.
    // Return infinity to encourage exploration or handle as an error.
    if (!parent_node || parent_node->VisitCount() == 0)
    {
        return std::numeric_limits<double>::infinity();
    }

    const double value_term = m_total_reward_ / m_visit_count_;
    const double exploration_term = c * std::sqrt(std::log(static_cast<double>(parent_node->VisitCount())) / m_visit_count_);
    
    return value_term + exploration_term;
}

bool Node::IsLeafNode() const
{
    return m_child_action_.empty();
}

bool Node::HasBeenSampled() const
{
    return m_visit_count_ > 0;
}

int Node::VisitCount() const
{
    return m_visit_count_;
}

double Node::TotalReward() const
{
    return m_total_reward_;
}

std::shared_ptr<Action> Node::SelectAction()
{
    if (m_child_action_.empty())
    {
        if (m_logger_) m_logger_->warn("Node '{}' has no children. Cannot select action.", Name());
        return nullptr;
    }
    
    // Select the child action that has been visited most often (exploitation)
    shared_ptr<Action> best_child = nullptr;
    int max_visits = -1;

    if (m_logger_) {
        std::stringstream ss;
        ss << "  Node '" << Name() << "' - Final Action Selection (highest visit count):" << std::endl;
        for (const auto& child : m_child_action_) {
            if (auto target = child->Target()) {
                ss << "    - Action leading to '" << target->Name()
                   << std::format("(T:{:.4f} N:{})", target->TotalReward(), target->VisitCount()) << std::endl;
            } else {
                 ss << "    - Action leading to (nullptr)" << std::endl;
            }
        }
        m_logger_->debug("{}", ss.str());
    }

    for (const auto& child : m_child_action_)
    {
        auto target = child->Target();
        if (target && target->VisitCount() > max_visits)
        {
            max_visits = target->VisitCount();
            best_child = child;
        }
    }
    if (m_logger_ && best_child && best_child->Target()) m_logger_->debug("  Node '{}' final selection: action leading to '{}' with {} visits.", Name(), best_child->Target()->Name(), max_visits);

    return best_child;
}






