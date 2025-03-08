#ifndef RANDOM_ACTION_STRATEGY_H
#define RANDOM_ACTION_STRATEGY_H

#include "rollout_strategy_interface.h"

namespace sophia::monte_carlo::models
{
    class Action;

    class RandomRolloutStrategy final : public RolloutStrategyInterface
    {
    public:
        [[nodiscard]] const_action_ptr select_action(std::vector<const_action_ptr> actions) const override;

    };
}

#endif //RANDOM_ACTION_STRATEGY_H
