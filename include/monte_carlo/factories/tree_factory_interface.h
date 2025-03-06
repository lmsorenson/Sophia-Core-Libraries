#ifndef TREE_FACTORY_INTERFACE_H
#define TREE_FACTORY_INTERFACE_H

#include <memory>

namespace sophia::monte_carlo::models
{
    class Node;
    class Action;
    class ActionSelectStrategyInterface;
}

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
        [[nodiscard]] virtual SharedAction CreateAction(SharedNode parent) const = 0;
        [[nodiscard]] virtual SharedActionSelectStrategy CreateStrategy() const = 0;
    };
}

#endif //TREE_FACTORY_INTERFACE_H
