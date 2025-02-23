#include <monte_carlo/factories/tree_factory.h>

using sophia::monte_carlo::factories::TreeFactory;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::ActionSelectStrategyInterface;
using std::shared_ptr;
using std::make_shared;

shared_ptr<Node> TreeFactory::CreateNode(std::string name) const
{
    return nullptr;
}

shared_ptr<ActionSelectStrategyInterface> TreeFactory::CreateStrategy() const
{
    return nullptr;
}

