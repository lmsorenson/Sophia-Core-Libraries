#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>
#include <monte_carlo/models/rollout_strategy_interface.h>
#include <monte_carlo/factories/tree_factory_interface.h>
#include <cmath>
#include <utility>
#include <iostream>

using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::factories::ITreeFactory;
using std::string;
using std::shared_ptr;
using std::vector;

Node::Node(string name)
    : m_name_(std::move(name))
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

    if (auto sp = m_parent_action_.lock())
    {
        const auto parent = sp->Source();
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
    return m_visit_count_ > 0;
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
    const vector<shared_ptr<Action>> child_nodes = GetAvailableActions();
    for(const auto& child : child_nodes)
    {
        child->Generate();
        auto target = child->Target();
        std::cout << Name() << " adding child " << target->Name() << std::endl;
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
        std::cout
        << "Rollout " << Name()
        << " is terminal state."
        << std::endl;
        return this->Value();
    }

    auto select_strategy = RolloutStrategy();

    vector<shared_ptr<Action>> actions;
    if (m_child_action_.empty())
    {
        actions = GetAvailableActions();
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
    m_total_reward_ += reward;
    m_visit_count_++;
    std::cout << Name() << ", t=" << m_total_reward_ << ", n=" << m_visit_count_ << std::endl;

    std::shared_ptr<Node> node = nullptr;
    if (auto sp = m_parent_action_.lock())
    {
        node = sp->Source();
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






