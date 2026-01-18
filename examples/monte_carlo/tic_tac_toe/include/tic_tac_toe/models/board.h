#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <vector>
#include <tic_tac_toe/models/player.h>
#include <tic_tac_toe/models/position.h>
#include <tic_tac_toe/enums/alignment.h>
#include "tic_tac_toe/common_aliases.h" // Centralized tic_tac_toe aliases


namespace sophia::monte_carlo::tic_tac_toe::models
{
    class Position;

    /**
     * @class Board
     * @brief A Tic Tac Toe board.
     */
    class Board
    {
    public:
        /**
         * @brief Creates a default Tic Tac Toe board.
         * @param logger The logger instance for the board to use.
         */
        explicit Board(const sophia::monte_carlo::logger_ptr& logger);

        /**
         * @brief creates a copy of a Tic Tac Toe board.
         * @param other
         */
        Board(const Board &other);

        /**
         * @brief Moves a Tic Tac Toe board.
         * @param other
         */
        Board(Board &&other) noexcept;

        /**
         * @brief The assignment operator for a Tic Tac Toe Board.
         * @param other
         * @return a Board
         */
        Board & operator=(const Board &other);

        /**
         * @brief The assignment operator for a Tic Tac Toe Board.
         * @param other
         * @return a Board
         */
        Board & operator=(Board &&other) noexcept;

        /**
         * @brief Set a position.
         * @param new_position
         */
        void SetPosition(const Position &new_position);

        /**
         * @brief The last placed symbol.
         * @return A Symbol value X, O, or None.
         */
        [[nodiscard]] enums::Symbol LastPlaced() const;

        /**
         * @brief Returns the Open Positions on the board.  These are the positions where there is no X or O.
         * @return The Open positions on the board.
         */
        [[nodiscard]] std::vector<std::shared_ptr<const Position>> GetOpenPositions() const;

        /**
         * @brief Creates a copy of the board with the given move applied.
         * @param position The position to apply.
         * @return The new board with the position applied.
         */
        [[nodiscard]] std::shared_ptr<const Board> WithMove(const Position& position) const;

        /**
         * @brief Gets lines of positions
         * @param alignment The line alignment
         * @return
         */
        [[nodiscard]] std::vector<std::vector<enums::Symbol>> GetLines(enums::Alignment alignment) const;

        /**
         * @brief Gets the winner of the game if one exists.
         * @return The winner of the game, nullptr if there is no winner.
         */
        [[nodiscard]] std::shared_ptr<std::pair<enums::Symbol, bool>> Winner() const;

        /**
         * @brief Gets the number of marked positions on the board.
         * @return The count of X's and O's on the board.
         */
        [[nodiscard]] int GetMarkCount() const;

        /**
         * @brief Prints the game board to the console.
         */
        void Print() const;

    private:
        std::vector<std::vector<std::shared_ptr<const Position>>> m_tiles_;
        enums::Symbol last_placed_ = enums::Symbol::None;
        logger_ptr m_logger_; // Member to hold the logger instance
    };
}

#endif //TIC_TAC_TOE_BOARD_H
