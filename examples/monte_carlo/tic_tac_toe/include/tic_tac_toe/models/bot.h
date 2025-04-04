#ifndef BOT_H
#define BOT_H
#include <tic_tac_toe/models/player.h>

namespace sophia::examples::tic_tac_toe::models
{
    class Bot : public Player
    {
    public:
        explicit Bot(Symbol symbol);

        [[nodiscard]] std::shared_ptr<monte_carlo::models::Action> GenerateAction(const std::shared_ptr<monte_carlo::models::Node> &node) const override;
    };
}

#endif //BOT_H
