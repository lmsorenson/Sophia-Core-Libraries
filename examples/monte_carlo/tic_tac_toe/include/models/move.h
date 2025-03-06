#ifndef MOVE_H
#define MOVE_H

#include <monte_carlo/models/action.h>

namespace sophia::examples::tic_tac_toe::models
{
    using monte_carlo::models::Node;

    class Move : public monte_carlo::models::Action
    {
    public:
        explicit Move(const std::shared_ptr<monte_carlo::models::Node> &source);


        [[nodiscard]] virtual std::shared_ptr<Node> Target() const override;
    };
}

#endif //MOVE_H