#ifndef MOCK_TREE_FACTORY_H
#define MOCK_TREE_FACTORY_H

#include <monte_carlo/factories/tree_factory_interface.h>

namespace sophia::monte_carlo::models
{
    class Node;
}

namespace sophia::monte_carlo::mocks
{
    using models::Node;
    using models::RolloutStrategyInterface;
    using factories::TreeFactoryBase;

    class MockRolloutStrategy;

    class MockTreeFactory : public TreeFactoryBase<bool, int>
    {
    public:
        ~MockTreeFactory() override = default;

        [[nodiscard]] node_ptr CreateNode(std::string name) const override;
        [[nodiscard]] node_ptr CreateNode(std::string name, bool state) const override;
        [[nodiscard]] action_ptr CreateAction(node_base_ptr node, int change) const override;
        [[nodiscard]] rollout_strategy_ptr CreateStrategy() const override;
    };
}

#endif //MOCK_TREE_FACTORY_H
