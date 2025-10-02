#ifndef HUMAN_H
#define HUMAN_H
#include <tic_tac_toe/models/player.h>
#include <tic_tac_toe/models/board.h>

namespace sophia::examples::tic_tac_toe::models
{
    /**
     * @class Human
     * @brief A human Tic Tac Toe Player
     */
    class Human : public Player
    {
    public:
        explicit Human(Symbol symbol);

        [[nodiscard]] std::shared_ptr<const Position> NextMove() const override;
        void Update(std::string message) override;
    };
}

#endif //HUMAN_H
