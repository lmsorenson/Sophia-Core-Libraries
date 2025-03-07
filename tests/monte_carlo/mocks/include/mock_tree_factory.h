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
    using models::ActionSelectStrategyInterface;
    using factories::ITreeFactory;

    class MockActionSelectStrategy;

    class MockTreeFactory : public ITreeFactory<int>
    {
    public:
        ~MockTreeFactory() override = default;

        [[nodiscard]] SharedNode CreateNode(std::string name) const override;
        [[nodiscard]] SharedAction CreateAction(std::shared_ptr<NodeBase<int>> node, int change) const override;
        [[nodiscard]] SharedActionSelectStrategy CreateStrategy() const override;
    };
}

#endif //MOCK_TREE_FACTORY_H
