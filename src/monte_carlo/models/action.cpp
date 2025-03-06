#include <monte_carlo/models/action.h>
#include <monte_carlo/models/node.h>
#include <utility>

using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;

Action::Action(const std::shared_ptr<Node>& source)
{
    m_source_node_ = source;
}

std::shared_ptr<Node> Action::Source() const
{
    return m_source_node_.lock();
}

double Action::UpperConfidenceBound() const
{
    if (auto sp = Target())
    {
        return sp->UpperConfidenceBound();
    }

    return 0.0;
}





