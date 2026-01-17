#ifndef RANDOM_ACTION_STRATEGY_H
#define RANDOM_ACTION_STRATEGY_H

#include "rollout_strategy_interface.h"

namespace sophia::monte_carlo::models
{
    class Action;

    /**
     * @brief A concrete implementation of the RolloutStrategyInterface that selects an action randomly.
     *
     * This strategy provides a simple and fast way to run simulations by choosing actions
     * uniformly at random from the list of available options. It is often used as a default
     * or baseline strategy in MCTS.
     */
    class RandomRolloutStrategy final : public RolloutStrategyInterface
    {
    public:
        /**
         * @brief Selects a random action from a vector of available actions.
         * @param actions A vector of shared pointers to the available actions.
         * @return A shared pointer to the randomly selected action.
         */
        [[nodiscard]] action_ptr select_action(std::vector<action_ptr> actions) const override;

    };
}

#endif //RANDOM_ACTION_STRATEGY_H
