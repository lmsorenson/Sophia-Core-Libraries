#ifndef ACTION_SELECTION_STRATEGY_INTERFACE_H
#define ACTION_SELECTION_STRATEGY_INTERFACE_H

#include <monte_carlo/models/action.h>

#include <iostream>
#include <memory>
#include <ostream>
#include <vector>

namespace sophia::monte_carlo::models
{
    class RolloutStrategyInterface
    {
    protected:
        using const_action_ptr = std::shared_ptr<const Action>;

    public:
        RolloutStrategyInterface() = default;
        virtual ~RolloutStrategyInterface() = default;

        [[nodiscard]] virtual const_action_ptr select_action(std::vector<const_action_ptr> actions) const = 0;
    };
}


#endif //ACTION_SELECTION_STRATEGY_INTERFACE_H
