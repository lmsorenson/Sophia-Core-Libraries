#ifndef TIC_TAC_TOE_FACTORY_H
#define TIC_TAC_TOE_FACTORY_H

#include <models/position.h>
#include <monte_carlo/factories/tree_factory_interface.h>
#include <monte_carlo/models/node_base.h>

namespace sophia::examples::tic_tac_toe::factories
{
    class TicTacToeFactory : public monte_carlo::factories::ITreeFactory<models::Position>
    {
    public:
        ~TicTacToeFactory() override = default;

        [[nodiscard]] SharedNode CreateNode(std::string name) const override;

        [[nodiscard]] SharedAction CreateAction(std::shared_ptr<NodeBase<models::Position>> node, models::Position change) const override;

        [[nodiscard]] SharedActionSelectStrategy CreateStrategy() const override;
    };
}

#endif //TIC_TAC_TOE_FACTORY_H
