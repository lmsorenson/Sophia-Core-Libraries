#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>
#include <monte_carlo/models/rollout_strategy_interface.h>
#include <monte_carlo/factories/tree_factory_interface.h>
#include <cmath>
#include <utility>
#include <logging/ilogger.h> // Added include for ILogger

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
}

void Node::SetParent(const std::shared_ptr<Action>& action)
{
    m_parent_action_ = action;
}

std::shared_ptr<Action> Node::SelectBestAction() const
{
    double best_score = 0;
    shared_ptr<Action> best_child = nullptr;

    for (const auto& child : m_child_action_)
    {
        const double current_score = child->UpperConfidenceBound(2);
        auto target = child->Target();
        if (m_logger_) m_logger_->debug("UCB({}) = {}", target->Name(), current_score);

        if (best_child == nullptr)
        {
            best_score = current_score;
            best_child = child;
        }

        if (current_score > best_score)
        {
            best_score = current_score;
            best_child = child;
        }
    }

    return best_child;
}

shared_ptr<Node> Node::Expand()
{
    const vector<shared_ptr<Action>> child_nodes = this->GetAvailableActions();
    for(const auto& child : child_nodes)
    {
        child->Generate();
        auto target = child->Target();
        if (m_logger_) m_logger_->debug("{} adding child {}", Name(), target->Name());
        m_child_action_.push_back(child);
        target->SetParent(child);
    }

    if (m_child_action_.empty())
    {
        return nullptr;
    }

    const auto front = m_child_action_.front();
    return front->Target();
}

double Node::Rollout()
{
    if (this->IsTerminalState())
    {
        if (m_logger_) m_logger_->debug("Rollout {} is terminal state.", Name());
        this->Print();
        return this->Value();
    }

    auto select_strategy = RolloutStrategy();

    vector<shared_ptr<Action>> actions;
    if (m_child_action_.empty())
    {
        actions = this->GetAvailableActions();
    }
    else
    {
        actions = m_child_action_;
    }

    if (const auto selected_action = select_strategy->select_action(actions))
    {
        const auto new_node = selected_action->Target();

        return new_node->Rollout();
    }

    return -1;
}

void Node::Backpropagate(const double reward)
{
    if (m_visit_count_ + 1 > std::numeric_limits<unsigned long>::max())
    {
        throw std::runtime_error("Node::Backpropagate");
    }

    if (m_total_reward_ + reward > std::numeric_limits<double>::max()
        || m_total_reward_ + reward < std::numeric_limits<double>::lowest())
    {
        throw std::runtime_error("Node::Backpropagate");
    }

    m_total_reward_ += reward;
    m_visit_count_++;

    if (m_logger_) m_logger_->debug("{}, t={}, n={}", Name(), m_total_reward_, m_visit_count_);

    std::shared_ptr<Node> node = nullptr;
    if (const auto sp = m_parent_action_.lock())
    {
        node = sp->Source();
        node->Backpropagate(reward);
    }
}

std::string Node::Name() const
{
    return m_name_;
}

double Node::UpperConfidenceBound(const int c) const
{
    const auto V = m_total_reward_ / m_visit_count_;
    int N = 0;

    if (const auto sp = m_parent_action_.lock())
    {
        const auto parent = sp->Source();
        N = parent->VisitCount();
    }

    const int n = m_visit_count_;
    if (n == 0)
    {
        return std::numeric_limits<double>::infinity();
    }

    const auto logN = std::log(N);
    const auto sql = std::sqrt(logN/n);

    return V + c * sql;
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
    double best_score = 0;
    shared_ptr<Action> best_child = nullptr;

    for (const auto& child : m_child_action_)
    {
        const double current_score = child->UpperConfidenceBound(0);
        const auto target = child->Target();
        if (m_logger_) m_logger_->debug("UCB({}) = {}", target->Name(), current_score);

        if (best_child == nullptr)
        {
            best_score = current_score;
            best_child = child;
        }

        if (current_score > best_score)
        {
            best_score = current_score;
            best_child = child;
        }
    }

    return best_child;
}






