#include <monte_carlo/models/action.h>
#include <monte_carlo/models/node.h>
#include <utility>

using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;

Action::Action(std::shared_ptr<Node> source, std::shared_ptr<Node> target)
{
    m_source_node_ = std::move(source);
    m_target_node_ = std::move(target);
}

std::shared_ptr<Node> Action::Source() const
{
    return m_source_node_.lock();
}

std::shared_ptr<Node> Action::Target() const
{
    return m_target_node_.lock();
}

double Action::UpperConfidenceBound() const
{
    if (auto sp = m_target_node_.lock())
    {
        return sp->UpperConfidenceBound();
    }

    return 0.0;
}





