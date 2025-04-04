#ifndef HUMAN_H
#define HUMAN_H
#include <tic_tac_toe/models/player.h>
#include <tic_tac_toe/models/board.h>

namespace sophia::examples::tic_tac_toe::models
{
    class Human : public Player
    {
    public:
        explicit Human(Symbol symbol);

        [[nodiscard]] std::shared_ptr<monte_carlo::models::Action> GenerateAction(const std::shared_ptr<monte_carlo::models::Node> &node) const override;
    };
}

#endif //HUMAN_H
