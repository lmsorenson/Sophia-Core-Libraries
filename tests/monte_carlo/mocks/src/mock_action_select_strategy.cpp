#include <mock_action_select_strategy.h>

using sophia::monte_carlo::mocks::MockActionSelectStrategy;
using sophia::monte_carlo::models::Action;
using std::shared_ptr;
using std::vector;

shared_ptr<Action> MockActionSelectStrategy::select_action(vector<shared_ptr<Action>> actions) const
{
    if (!actions.empty())
        return actions.front();

    return nullptr;
}