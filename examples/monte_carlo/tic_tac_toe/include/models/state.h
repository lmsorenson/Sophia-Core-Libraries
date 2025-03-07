#ifndef STATE_H
#define STATE_H

#include <monte_carlo/models/node_base.h>
#include <models/board.h>

namespace sophia::examples::tic_tac_toe::models
{
    using monte_carlo::factories::ITreeFactory;
    using monte_carlo::models::Action;

    class State : public NodeBase<Board, Position>
    {
    public:
        explicit State(const std::string& name, TileState player, const std::shared_ptr<const ITreeFactory<Board, Position>>& interface);
        explicit State(const std::string& name, Board board, const std::shared_ptr<const ITreeFactory<Board, Position>>& interface);

        [[nodiscard]] std::vector<std::shared_ptr<Action>> GetAvailableActions() override;

        [[nodiscard]] bool IsTerminalState() const override;

        [[nodiscard]] double Value() const override;
    };
}

#endif //STATE_H