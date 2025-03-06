#ifndef STATE_H
#define STATE_H

#include <monte_carlo/models/node_base.h>
#include <models/board.h>

namespace sophia::examples::tic_tac_toe::models
{
    using monte_carlo::factories::ITreeFactory;
    using monte_carlo::models::Action;

    class State : public monte_carlo::models::NodeBase<Position>
    {
    public:
        explicit State(const std::string& name, const std::shared_ptr<const ITreeFactory<Position>>& interface);

        [[nodiscard]] std::vector<std::shared_ptr<Action>> GetAvailableActions() const override;

        [[nodiscard]] bool IsTerminalState() const override;

        [[nodiscard]] double Value() const override;

    private:
        Board m_board_;
    };
}

#endif //STATE_H