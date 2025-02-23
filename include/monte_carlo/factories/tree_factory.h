#ifndef TREE_FACTORY_H
#define TREE_FACTORY_H

#include <monte_carlo/factories/tree_factory_interface.h>

namespace sophia::monte_carlo::factories
{
    class TreeFactory : public ITreeFactory
    {
    public:
        ~TreeFactory() override = default;

        [[nodiscard]] std::shared_ptr<models::Node> CreateNode(std::string name) const override;
        [[nodiscard]] std::shared_ptr<models::ActionSelectStrategyInterface> CreateStrategy() const override;
    };
}

#endif //TREE_FACTORY_H
