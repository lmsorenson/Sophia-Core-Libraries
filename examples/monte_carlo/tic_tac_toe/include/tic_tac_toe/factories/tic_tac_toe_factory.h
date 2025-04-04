#ifndef TIC_TAC_TOE_FACTORY_H
#define TIC_TAC_TOE_FACTORY_H

#include <tic_tac_toe/models/game_state.h>
#include <tic_tac_toe/models/position.h>
#include <monte_carlo/factories/tree_factory_interface.h>
#include <monte_carlo/models/node_base.h>

namespace sophia::examples::tic_tac_toe::factories
{
    class TicTacToeFactory : public monte_carlo::factories::TreeFactoryBase<models::GameState, models::Position>
    {
    public:
        ~TicTacToeFactory() override = default;

        [[nodiscard]] node_ptr CreateNode(std::string name) const override;

        [[nodiscard]] node_ptr CreateNode(std::string name, models::GameState game_state) const override;

        [[nodiscard]] action_ptr CreateAction(std::shared_ptr<NodeBase<models::GameState, models::Position>> node, models::Position change) const override;

        [[nodiscard]] rollout_strategy_ptr CreateStrategy() const override;
    };
}

#endif //TIC_TAC_TOE_FACTORY_H
