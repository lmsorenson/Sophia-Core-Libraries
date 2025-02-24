#include <mock_node.h>
#include <mock_tree_factory.h>

using sophia::monte_carlo::mocks::MockTreeFactory;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::mocks::MockNode;
using sophia::monte_carlo::models::ActionSelectStrategyInterface;
using std::shared_ptr;
using std::string;


shared_ptr<Node> MockTreeFactory::CreateNode(string name) const
{
    return std::make_shared<MockNode>(name, shared_from_this());
}

shared_ptr<ActionSelectStrategyInterface> MockTreeFactory::CreateStrategy() const
{
    return std::make_shared<MockActionSelectStrategy>();
}