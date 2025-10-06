#ifndef BOT_H
#define BOT_H
#include <tic_tac_toe/models/player.h>
#include <monte_carlo/models/node.h>
#include <tic_tac_toe/observer/observer.h>

#include <memory>

#include "board.h"

namespace sophia::monte_carlo::tic_tac_toe::models
{
    /**
     * @class Bot
     * @brief A non-human Tic Tac Toe Player
     */
    class Bot : public Player
    {

    public:
        /**
         * @brief Creates a bot.
         * @param symbol The symbol that the bot places.
         * @param difficulty The skill level of the bot a decimal value from 0 to 1.
         */
        explicit Bot(enums::Symbol symbol, double difficulty);

        /**
         * @brief Prompts the bot to make its next move.
         * @return A shared pointer to the move made.
         */
        [[nodiscard]] std::shared_ptr<const Position> NextMove() const override;

        /**
         * @brief Updates the player's knowledge of the game.
         * @param message A message indicating the move made.
         * Expecting a 2-letter string consisting of
         * a letter, indicating the row of the placement,
         * followed by a number, indicating the column of the placement.
         * (i.e. 'B2')
         */
        void Update(std::string message) override;

    private:
        std::shared_ptr<monte_carlo::models::Node> node_;
        int iterations_;
    };
}

#endif //BOT_H
