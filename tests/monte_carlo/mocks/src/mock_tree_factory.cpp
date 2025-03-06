#include <mock_tree_factory.h>
#include <monte_carlo/models/action_select_strategy_interface.h>
#include <mock_node.h>
#include <mock_action.h>
#include <mock_action_select_strategy.h>
#include <memory>

using sophia::monte_carlo::mocks::MockTreeFactory;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::models::ActionSelectStrategyInterface;
using std::shared_ptr;
using std::make_shared;
using std::string;


shared_ptr<Node> MockTreeFactory::CreateNode(string name) const
{
    return make_shared<MockNode>(name, shared_from_this());
}

shared_ptr<Action> MockTreeFactory::CreateAction(shared_ptr<Node> parent) const
{
    return make_shared<MockAction>(parent);
}

shared_ptr<ActionSelectStrategyInterface> MockTreeFactory::CreateStrategy() const
{
    return make_shared<MockActionSelectStrategy>();
}