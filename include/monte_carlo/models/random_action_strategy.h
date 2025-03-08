#ifndef RANDOM_ACTION_STRATEGY_H
#define RANDOM_ACTION_STRATEGY_H

#include "rollout_strategy_interface.h"

namespace sophia::monte_carlo::models
{
    class Action;

    class RandomActionStrategy : public RolloutStrategyInterface
    {
    public:
        [[nodiscard]] std::shared_ptr<Action> select_action(std::vector<std::shared_ptr<Action>> actions) const override;

    };
}

#endif //RANDOM_ACTION_STRATEGY_H
