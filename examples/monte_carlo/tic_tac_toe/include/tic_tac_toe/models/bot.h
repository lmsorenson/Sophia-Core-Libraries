#ifndef BOT_H
#define BOT_H
#include <tic_tac_toe/models/player.h>
#include <monte_carlo/models/node.h>
#include <memory>

namespace sophia::examples::tic_tac_toe::models
{
    class Bot : public Player
    {

    public:
        explicit Bot(Symbol symbol);

        [[nodiscard]] std::shared_ptr<const Position> NextMove() const override;

    private:
        std::shared_ptr<sophia::monte_carlo::models::Node> node_;
    };
}

#endif //BOT_H
