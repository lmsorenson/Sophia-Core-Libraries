#ifndef TREE_FACTORY_INTERFACE_H
#define TREE_FACTORY_INTERFACE_H

#include <memory>
#include <string>
// Removed #include <logging/ilogger.h>
#include <monte_carlo/fwd.h> // Centralized forward declarations
#include <monte_carlo/common_aliases.h> // Centralized aliases

// Removed specific models namespace forward declarations
// namespace sophia::monte_carlo::models
// {
//     class Node;
//     template<typename TState, typename TChange>
//     class NodeBase;
//     class Action;
//     class RolloutStrategyInterface;
// }

namespace sophia::monte_carlo::factories
{
    using sophia::monte_carlo::models::NodeBase; // Import NodeBase for CreateAction parameter

    template<typename TState, typename TChange>
    class TreeFactoryBase : public std::enable_shared_from_this<TreeFactoryBase<TState, TChange>>
    {
    protected:
        // Removed internal using directives for aliases
        // using node_ptr = std::shared_ptr<models::Node>;
        // using node_base_ptr = std::shared_ptr<models::NodeBase<TState, TChange>>;
        // using action_ptr = std::shared_ptr<models::Action>;
        // using rollout_strategy_ptr = std::shared_ptr<models::RolloutStrategyInterface>;
        using state_ptr = std::shared_ptr<TState>; // This one is not centralized, depends on TState

    public:
        virtual ~TreeFactoryBase() = default;

        /**
         * Creates a new Node.
         * @param name the name of the new Node being created.
         * @returns a shared pointer to a Node.
         */
        [[nodiscard]] virtual sophia::monte_carlo::node_ptr CreateNode(std::string name) const = 0;

        /**
         * Creates a new Node.
         * @param name the name of the new Node being created.
         * @param state the state represented by the Node being created.
         * @returns a shared pointer to a Node.
         */
        [[nodiscard]] virtual sophia::monte_carlo::node_ptr CreateNode(std::string name, TState state) const = 0;

        /**
         * Creates a new Action.
         * @param node the source node for the action being created.
         * @param change the change being applied to the source node.
         * @returns a shared pointer to a Node.
         */
        [[nodiscard]] virtual sophia::monte_carlo::action_ptr CreateAction(sophia::monte_carlo::node_base_ptr<TState, TChange> node, TChange change) const = 0;

        /**
         * Creates a new Strategy.
         * @returns a shared pointer to a Rollout Strategy.
         */
        [[nodiscard]] virtual sophia::monte_carlo::rollout_strategy_ptr CreateStrategy() const = 0;
    };
}

#endif //TREE_FACTORY_INTERFACE_H
