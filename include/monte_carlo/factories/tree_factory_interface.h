#ifndef TREE_FACTORY_INTERFACE_H
#define TREE_FACTORY_INTERFACE_H

#include <memory>
#include <string>

namespace sophia::monte_carlo::models
{
    class Node;

    template<typename TState, typename TChange>
    class NodeBase;

    class Action;
    class RolloutStrategyInterface;
}

namespace sophia::monte_carlo::factories
{
    template<typename TState, typename TChange>
    class TreeFactoryBase : public std::enable_shared_from_this<TreeFactoryBase<TState, TChange>>
    {
    protected:
        using node_ptr = std::shared_ptr<models::Node>;
        using node_base_ptr = std::shared_ptr<models::NodeBase<TState, TChange>>;
        using action_ptr = std::shared_ptr<models::Action>;
        using rollout_strategy_ptr = std::shared_ptr<models::RolloutStrategyInterface>;
        using state_ptr = std::shared_ptr<TState>;

    public:
        virtual ~TreeFactoryBase() = default;

        [[nodiscard]] virtual node_ptr CreateNode(std::string name) const = 0;
        [[nodiscard]] virtual node_ptr CreateNode(std::string name, TState state) const = 0;
        [[nodiscard]] virtual action_ptr CreateAction(node_base_ptr node, TChange change) const = 0;
        [[nodiscard]] virtual rollout_strategy_ptr CreateStrategy() const = 0;
    };
}

#endif //TREE_FACTORY_INTERFACE_H
