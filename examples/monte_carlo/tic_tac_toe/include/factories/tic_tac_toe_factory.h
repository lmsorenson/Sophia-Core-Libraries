#ifndef TIC_TAC_TOE_FACTORY_H
#define TIC_TAC_TOE_FACTORY_H

#include <monte_carlo/factories/tree_factory_interface.h>

namespace sophia::examples::tic_tac_toe::factories
{
    class TicTacToeFactory : public monte_carlo::factories::ITreeFactory
    {
    public:
        ~TicTacToeFactory() override = default;

        [[nodiscard]] SharedNode CreateNode(std::string name) const override;

        [[nodiscard]] SharedAction CreateAction(SharedNode parent, SharedNode child) const override;

        [[nodiscard]] SharedActionSelectStrategy CreateStrategy() const override;
    };
}

#endif //TIC_TAC_TOE_FACTORY_H
