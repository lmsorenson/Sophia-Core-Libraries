#ifndef STATE_H
#define STATE_H

#include <monte_carlo/models/node_base.h>
#include <tic_tac_toe/models/game_state.h>

namespace sophia::monte_carlo::tic_tac_toe::models
{
    using factories::TreeFactoryBase;
    using monte_carlo::models::Action;

    /**
     * @class State
     * @brief The Monte Carlo state node of a Tic Tac Toe game.
     */
    class State : public NodeBase<GameState, Position>
    {
    public:
        /**
         * Creates an instance of a Tic Tac Toe State.
         * @param name The name of the State.
         * @param tree_factory A tree factory that can
         * be used to create the following states.
         */
        explicit State(const std::string& name, const const_factory_ptr& tree_factory);

        /**
         * Creates an instance of a Tic Tac Toe State.
         * @param name The name of the State.
         * @param game_state A Tic Tac Toe GameState.
         * @param tree_factory A tree factory that can
         * be used to create the following states.
         */
        explicit State(const std::string& name, GameState game_state, const const_factory_ptr& tree_factory);

        /**
         * @brief Gets all available actions that can be
         * made at this given state.
         * @return A vector of shared pointers to Actions
         * that can be applied at this given state of play.
         */
        [[nodiscard]] std::vector<action_ptr> GetAvailableActions() override;

        /**
         * @brief Determines if this state is the end of the Game.
         * @return True if a winner can be determined, False if a
         * winner cannot be determined.
         */
        [[nodiscard]] bool IsTerminalState() const override;

        /**
         * The value or score of this state for the given owning
         * player.
         * @return A double value representing a score for the
         * state.
         */
        [[nodiscard]] double Value() const override;

        /**
         * @brief Selects the available action with the given name.
         * @param action_name A 2-letter name for a move.
         * @return The action represented by the action name.
         */
        action_ptr SelectAction(std::string action_name) override;

        /**
         * Prints the board at this state of the Game to the
         * console.
         */
        void Print() const override;
    };
}

#endif //STATE_H