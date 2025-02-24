#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>
#include <monte_carlo/factories/tree_factory.h>
#include <cmath>
#include <utility>
#include <iostream>

using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::factories::ITreeFactory;
using std::string;
using std::shared_ptr;
using std::vector;

Node::Node(string name, shared_ptr<const ITreeFactory> factory)
    : m_name_(std::move(name))
    , m_factory_(std::move(factory))
{
}

void Node::SetParent(std::shared_ptr<Action> action)
{
    m_parent_action_ = std::move(action);
}


double Node::UpperConfidenceBound() const
{
    const auto V = m_total_reward_ / m_visit_count_;
    int N = 0;
    if (m_parent_action_ != nullptr)
    {
        const auto parent = m_parent_action_->Source();
        N = parent->VisitCount();
    }
    const int n = m_visit_count_;

    if (n == 0)
        return std::numeric_limits<double>::infinity();

    constexpr int c = 2;

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
    return m_visit_count_ != 0;
}

std::shared_ptr<Action> Node::SelectBestAction() const
{
    double best_score = 0;
    shared_ptr<Action> best_child = nullptr;

    for (const auto& child : m_child_action_)
    {
        const double current_score = child->UpperConfidenceBound();
        auto target = child->Target();
        std::cout<< "UCB(" << target->Name() << ") = " << current_score
        << std::endl;

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
    vector<shared_ptr<Node>> child_nodes = GetAvailableActions();
    for(const auto& child : child_nodes)
    {
        std::cout << Name() << " adding child " << child->Name() << std::endl;
        auto action = m_factory_->CreateAction(shared_from_this(), child);
        m_child_action_.push_back(action);
        child->SetParent(action);
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
        std::cout
        << "Rollout " << Name() << " is terminal state. value: " << this->Value()
        << std::endl;
        return this->Value();
    }

    std::cout
    << "Rollout " << Name() << " is NOT terminal state."
    << std::endl;

    auto select_strategy = m_factory_->CreateStrategy();

    const auto selected_action = select_strategy->select_action(m_child_action_);

    const auto new_node = selected_action->Target();

    return new_node->Rollout();
}

void Node::Backpropagate(const double reward)
{
    m_total_reward_ += reward;
    m_visit_count_++;
    std::cout
    << Name()
    << ", t=" << m_total_reward_
    << ", n=" << m_visit_count_
    << std::endl;

    std::shared_ptr<Node> node = nullptr;
    if (m_parent_action_ != nullptr)
    {
        node = m_parent_action_->Source();
        node->Backpropagate(reward);
    }
}

std::string Node::Name() const
{
    return m_name_;
}

int Node::VisitCount() const
{
    return m_visit_count_;
}

int Node::TotalReward() const
{
    return m_total_reward_;
}






