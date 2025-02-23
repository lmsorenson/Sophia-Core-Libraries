#ifndef MOCK_TREE_FACTORY_H
#define MOCK_TREE_FACTORY_H

#include <monte_carlo/factories/tree_factory_interface.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action_select_strategy_interface.h>

#include "mock_action_select_strategy.h"

using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::ActionSelectStrategyInterface;
using sophia::monte_carlo::tree_search_algorithm_tests::MockActionSelectStrategy;
using sophia::monte_carlo::tree_search_algorithm_tests::MockNode;

class MockTreeFactory : public sophia::monte_carlo::factories::ITreeFactory
{
public:
    ~MockTreeFactory() override = default;

    [[nodiscard]] std::shared_ptr<Node> CreateNode(std::string name) const override
    {
        return std::make_shared<MockNode>(name, shared_from_this());
    }
    [[nodiscard]] std::shared_ptr<ActionSelectStrategyInterface> CreateStrategy() const override
    {
        return std::make_shared<MockActionSelectStrategy>();
    }
};

#endif //MOCK_TREE_FACTORY_H
