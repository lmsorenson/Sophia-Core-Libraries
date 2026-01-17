#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <memory>

#include <tic_tac_toe/models/board.h>

namespace sophia::monte_carlo::tic_tac_toe::models
{
    /**
     * @class GameState
     * @brief A state refers to the state from one player's perspective.
     * This is for the monte carlo engine.
     */
    class GameState
    {
    public:
        /**
         * @brief Creates an instance of GameState given an owning player and a value for the board.
         * @param you The owning Player of the state.
         * @param board The board info in the given state.
         */
        explicit GameState(const_player_ptr you, std::shared_ptr<const Board> board);

        /**
         * Creates an instance of GameState
         * @param you The owning Player of the state.
         * @param board The board info in the given state.
         * @param last_placed The Symbol last placed.
         */
        explicit GameState(const_player_ptr you, std::shared_ptr<const Board> board, enums::Symbol last_placed);

        /**
         * @brief Creates a copy of the GameState with the given move applied.
         * @param position The move that will be applied.
         * @return A shared pointer to a new GameState with the move applied.
         */
        [[nodiscard]] std::shared_ptr<const GameState> ApplyMove(const Position& position) const;

        /**
         * @brief Gets the current player of the game.
         * @return A shared pointer to the Player whose turn it is to move.
         */
        [[nodiscard]] std::shared_ptr<const Player> CurrentPlayer() const;

        /**
         * @brief Gets the owning Player of the GameState.
         * @return A shared pointer to the owning player of the GameState.
         */
        [[nodiscard]] std::shared_ptr<const Player> You() const;

        /**
         * @brief Gets the winner of the game.
         * @return A shared pointer to the winner of the Tic Tac Toe game.
         */
        [[nodiscard]] std::shared_ptr<std::pair<enums::Symbol, bool>> Winner() const;

        /**
         * @brief GetOpenPositions
         * @return A vector of shared pointers to Positions that don't have a mark yet.
         */
        [[nodiscard]] std::vector<std::shared_ptr<const Position>> GetOpenPositions() const;

        /**
         * @brief The last placed Symbol.
         * @return The Symbol that was placed last.
         */
        [[nodiscard]] enums::Symbol LastPlaced() const;

        /**
         * @brief Get the board information for this GameState.
         * @return The Board data for this GameState.
         */
        [[nodiscard]] Board GetBoard() const;

        /**
         * @brief Gets the current turn number based on the number of marks on the board.
         * @return The current turn number.
         */
        [[nodiscard]] int GetTurnNumber() const;

        /**
         * @brief Prints the board info for this GameState.
         */
        void Print() const;

    private:
        std::shared_ptr<const Board> m_board_;
        std::shared_ptr<const Player> m_you_;
    };
}

#endif //GAME_STATE_H
