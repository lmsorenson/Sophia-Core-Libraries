#ifndef ACTION_SELECTION_STRATEGY_INTERFACE_H
#define ACTION_SELECTION_STRATEGY_INTERFACE_H
#include <iostream>
#include <memory>
#include <ostream>
#include <vector>

namespace sophia::monte_carlo::models
{
    class Action;

    class ActionSelectStrategyInterface
    {
    public:
        ActionSelectStrategyInterface() = default;
        virtual ~ActionSelectStrategyInterface() = default;

        virtual std::shared_ptr<Action> select_action(std::vector<std::shared_ptr<Action>> actions) const = 0;
    };
}


#endif //ACTION_SELECTION_STRATEGY_INTERFACE_H
