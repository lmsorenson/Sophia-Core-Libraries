#ifndef TREE_FACTORY_INTERFACE_H
#define TREE_FACTORY_INTERFACE_H

#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action_select_strategy_interface.h>

namespace sophia::monte_carlo::factories
{
    class ITreeFactory : public std::enable_shared_from_this<ITreeFactory>
    {
    public:
        virtual ~ITreeFactory() = default;

        [[nodiscard]] virtual std::shared_ptr<models::Node> CreateNode(std::string name) const = 0;
        [[nodiscard]] virtual std::shared_ptr<models::ActionSelectStrategyInterface> CreateStrategy() const = 0;
    };
}

#endif //TREE_FACTORY_INTERFACE_H
