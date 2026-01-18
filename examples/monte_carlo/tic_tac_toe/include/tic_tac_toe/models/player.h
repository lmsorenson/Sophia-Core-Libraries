#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <tic_tac_toe/models/position.h>
#include <tic_tac_toe/enums/symbol.h>
#include <tic_tac_toe/observer/observer.h>
#include <monte_carlo/common_aliases.h> // Centralized logger_ptr alias

namespace sophia::monte_carlo::tic_tac_toe::models
{
    /**
     * @class Player
     * @brief A Player in a Tic Tac Toe Game
     */
    class Player : public std::enable_shared_from_this<Player>, public observer::Observer
    {
    public:
        explicit Player(enums::Symbol symbol, const sophia::monte_carlo::logger_ptr& logger);
        virtual ~Player() = default;

        /**
         * @brief The Symbol used by the Player.
         * @return
         */
        [[nodiscard]] enums::Symbol symbol() const;

        /**
         * @brief Prompts the Player to make its next move.
         * @return A shared pointer to the move made.
         */
        [[nodiscard]] virtual std::shared_ptr<const Position> NextMove() const = 0;

        /**
         * @brief Assigns a value of the board state from the perspective of this Player.
         * @param board The board information for the current game.
         * @return A double value that represents the score of the game from the
         * perspective of the Player.
         */
        [[nodiscard]] double Value(const class Board &board) const;

    protected:
        enums::Symbol m_player_symbol_ = enums::Symbol::None;
        sophia::monte_carlo::logger_ptr m_logger_; // Member to hold the logger instance
    };
}

#endif //PLAYER_H
