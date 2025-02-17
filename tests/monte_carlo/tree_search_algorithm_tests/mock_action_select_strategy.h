#ifndef MOCK_ACTION_SELECT_STRATEGY_H
#define MOCK_ACTION_SELECT_STRATEGY_H
#include <gmock/gmock.h>
#include <monte_carlo/models/action.h>
#include <monte_carlo/models/action_select_strategy_interface.h>

namespace sophia::monte_carlo::tree_search_algorithm_tests
{
    using models::ActionSelectStrategyInterface;
    using models::Action;
    using std::shared_ptr;
    using std::vector;

    class MockActionSelectStrategy : public ActionSelectStrategyInterface
    {
    public:
        [[nodiscard]] shared_ptr<Action> select_action(std::vector<std::shared_ptr<Action>> actions) const override
        {
            if (!actions.empty())
                return actions.front();

            return nullptr;
        }
    };
}

#endif //MOCK_ACTION_SELECT_STRATEGY_H
