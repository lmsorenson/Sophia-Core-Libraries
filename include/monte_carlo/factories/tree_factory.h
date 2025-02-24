#ifndef TREE_FACTORY_H
#define TREE_FACTORY_H

#include <monte_carlo/factories/tree_factory_interface.h>

namespace sophia::monte_carlo::factories
{
    class TreeFactory : public ITreeFactory
    {
    public:
        ~TreeFactory() override = default;

        [[nodiscard]] SharedNode CreateNode(std::string name) const override;
        [[nodiscard]] SharedAction CreateAction(SharedNode parent, SharedNode child) const override;
        [[nodiscard]] SharedActionSelectStrategy CreateStrategy() const override;
    };
}

#endif //TREE_FACTORY_H
