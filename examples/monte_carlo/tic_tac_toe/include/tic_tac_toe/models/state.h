#ifndef STATE_H
#define STATE_H

#include <monte_carlo/models/node_base.h>
#include <tic_tac_toe/models/game_state.h>

namespace sophia::examples::tic_tac_toe::models
{
    using monte_carlo::factories::TreeFactoryBase;
    using monte_carlo::models::Action;

    class State : public NodeBase<GameState, Position>
    {
    public:
        explicit State(const std::string& name, const const_factory_ptr& interface);
        explicit State(const std::string& name, GameState game_state, const const_factory_ptr& interface);

        [[nodiscard]] std::vector<action_ptr> GetAvailableActions() override;

        [[nodiscard]] bool IsTerminalState() const override;

        [[nodiscard]] double Value() const override;

        action_ptr SelectAction(std::string action_name) override;

        node_ptr ApplyAction() override;

        void Print() const override;
    };
}

#endif //STATE_H