#ifndef BOT_H
#define BOT_H
#include <tic_tac_toe/models/player.h>
#include <monte_carlo/models/node.h>
#include <tic_tac_toe/observer/observer.h>

#include <memory>

#include "board.h"

namespace sophia::examples::tic_tac_toe::models
{
    /**
     * @class Bot
     * @brief A non-human Tic Tac Toe Player
     */
    class Bot : public Player
    {

    public:
        explicit Bot(enums::Symbol symbol, double difficulty);

        [[nodiscard]] std::shared_ptr<const Position> NextMove() const override;
        void Update(std::string message) override;

    private:
        std::shared_ptr<sophia::monte_carlo::models::Node> node_;
        int iterations_;
    };
}

#endif //BOT_H
