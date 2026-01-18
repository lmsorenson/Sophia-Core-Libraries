#ifndef TIC_TAC_TOE_HEURISTIC_ROLLOUT_STRATEGY_H
#define TIC_TAC_TOE_HEURISTIC_ROLLOUT_STRATEGY_H

#include <monte_carlo/models/rollout_strategy_interface.h>
#include <tic_tac_toe/models/game_state.h>
#include <tic_tac_toe/models/move.h>
#include <logging/ilogger.h>

#include <memory>
#include <vector>

namespace sophia::monte_carlo::tic_tac_toe::models
{
    using sophia::logging::logger_ptr;

    /**
     * @brief A heuristic rollout strategy for Tic-Tac-Toe.
     *
     * This strategy attempts to select the best action based on simple heuristic rules
     * to guide the Monte Carlo simulations towards more promising outcomes.
     */
    class HeuristicRolloutStrategy : public sophia::monte_carlo::models::RolloutStrategyInterface
    {
    public:
        /**
         * @brief Constructs a HeuristicRolloutStrategy.
         * @param current_game_state The current game state from which the rollout will start.
         * @param logger The logger instance.
         */
        explicit HeuristicRolloutStrategy(GameState current_game_state, const logger_ptr& logger);

        /**
         * @brief Selects an action from a vector of available actions based on heuristic rules.
         * @param actions A vector of shared pointers to the available actions. These are expected to be TicTacToe Move objects.
         * @return A shared pointer to the selected action (Move).
         */
        [[nodiscard]] action_ptr select_action(
            std::vector<action_ptr> actions) const override;

    private:
        /**
         * @brief Evaluates a given move (position) on the board.
         * @param board The board to evaluate the move on.
         * @param move The position of the move.
         * @param player_symbol The symbol of the player making the move.
         * @return A score representing the desirability of the move. Higher is better.
         */
        [[nodiscard]] int evaluate_move(const Board& board, const Position& move, enums::Symbol player_symbol) const;

        /**
         * @brief Checks if a given move results in a win for the specified player.
         * @param board The board to check.
         * @param move The move to test.
         * @param player_symbol The symbol of the player.
         * @return True if the move results in a win, false otherwise.
         */
        [[nodiscard]] bool check_for_win(const Board& board, const Position& move, enums::Symbol player_symbol) const;

        GameState m_current_game_state;
        logger_ptr m_logger;
    };
} // namespace sophia::monte_carlo::tic_tac_toe::models

#endif //TIC_TAC_TOE_HEURISTIC_ROLLOUT_STRATEGY_H
