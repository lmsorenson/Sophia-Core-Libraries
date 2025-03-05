#ifndef STATE_H
#define STATE_H

#include <monte_carlo/models/node.h>

namespace sophia::examples::tic_tac_toe::models
{
    using monte_carlo::factories::ITreeFactory;

    class State : public monte_carlo::models::Node
    {
    public:
        explicit State(const std::string& name, const std::shared_ptr<const ITreeFactory>& interface);

        [[nodiscard]] std::vector<std::shared_ptr<Node>> GetAvailableActions() const override;

        [[nodiscard]] bool IsTerminalState() const override;

        [[nodiscard]] double Value() const override;
    };
}

#endif //STATE_H