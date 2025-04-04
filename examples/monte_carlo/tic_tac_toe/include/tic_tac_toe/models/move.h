#ifndef MOVE_H
#define MOVE_H

#include <monte_carlo/models/action_base.h>

#include <tic_tac_toe/models/game_state.h>
#include <tic_tac_toe/models/position.h>

namespace sophia::examples::tic_tac_toe::models
{
    using monte_carlo::models::Node;
    using monte_carlo::factories::TreeFactoryBase;

    class Move : public monte_carlo::models::ActionBase<GameState, Position>
    {
    public:
        explicit Move(const std::shared_ptr<NodeBase<GameState, Position>> &source, Position change,
            std::shared_ptr<const TreeFactoryBase<GameState, Position>> factory);

        virtual std::string Name() const override;
        void Generate() override;
    };
}

#endif //MOVE_H