#ifndef HUMAN_H
#define HUMAN_H
#include <tic_tac_toe/models/player.h>
#include <tic_tac_toe/models/board.h>

namespace sophia::monte_carlo::tic_tac_toe::models
{
    /**
     * @class Human
     * @brief A human Tic Tac Toe Player
     */
    class Human : public Player
    {
    public:
        /**
         * @brief Creates an instance of a Human Player.
         * @param symbol The Symbol that this Player places.
         */
        explicit Human(enums::Symbol symbol);

        /**
         * @brief Prompts the Human to make its next move.
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
    };
}

#endif //HUMAN_H
