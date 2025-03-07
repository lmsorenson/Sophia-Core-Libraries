#include <monte_carlo/models/action.h>
#include <monte_carlo/models/node.h>
#include <utility>

using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;

double Action::UpperConfidenceBound() const
{
    if (const auto sp = Target())
    {
        return sp->UpperConfidenceBound();
    }

    return 0.0;
}





