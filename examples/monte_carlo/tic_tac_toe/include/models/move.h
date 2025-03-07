#ifndef MOVE_H
#define MOVE_H

#include <monte_carlo/models/action_base.h>

#include <models/Board.h>
#include <models/position.h>

namespace sophia::examples::tic_tac_toe::models
{
    using monte_carlo::models::Node;

    class Move : public monte_carlo::models::ActionBase<Board, Position>
    {
    public:
        explicit Move(const std::shared_ptr<NodeBase<Position>> &source, Position change);

        [[nodiscard]] std::shared_ptr<Node> Target() const override;
    };
}

#endif //MOVE_H