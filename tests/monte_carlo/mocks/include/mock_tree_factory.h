#ifndef MOCK_TREE_FACTORY_H
#define MOCK_TREE_FACTORY_H

#include <monte_carlo/factories/tree_factory_interface.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action_select_strategy_interface.h>
#include <mock_action_select_strategy.h>

namespace sophia::monte_carlo::mocks
{
    using models::Node;
    using models::ActionSelectStrategyInterface;
    using mocks::MockActionSelectStrategy;
    using factories::ITreeFactory;

    class MockTreeFactory : public ITreeFactory
    {
    public:
        ~MockTreeFactory() override = default;

        [[nodiscard]] SharedNode CreateNode(std::string name) const override;
        [[nodiscard]] SharedAction CreateAction(SharedNode parent, SharedNode child) const override;
        [[nodiscard]] SharedActionSelectStrategy CreateStrategy() const override;
    };
}

#endif //MOCK_TREE_FACTORY_H
