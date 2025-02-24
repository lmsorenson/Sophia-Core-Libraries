#ifndef TREE_FACTORY_INTERFACE_H
#define TREE_FACTORY_INTERFACE_H

#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action_select_strategy_interface.h>

namespace sophia::monte_carlo::factories
{
    class ITreeFactory : public std::enable_shared_from_this<ITreeFactory>
    {
    protected:
        using SharedNode = std::shared_ptr<models::Node>;
        using SharedAction = std::shared_ptr<models::Action>;
        using SharedActionSelectStrategy = std::shared_ptr<models::ActionSelectStrategyInterface>;

    public:
        virtual ~ITreeFactory() = default;

        [[nodiscard]] virtual SharedNode CreateNode(std::string name) const = 0;
        [[nodiscard]] virtual SharedAction CreateAction(SharedNode parent, SharedNode child) const = 0;
        [[nodiscard]] virtual SharedActionSelectStrategy CreateStrategy() const = 0;
    };
}

#endif //TREE_FACTORY_INTERFACE_H
