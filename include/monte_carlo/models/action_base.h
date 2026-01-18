#ifndef ACTION_BASE_H
#define ACTION_BASE_H

#include <memory>
#include <ostream>

#include <monte_carlo/models/action.h>
#include <monte_carlo/factories/tree_factory_interface.h>

#include "node_base.h"
#include <monte_carlo/common_aliases.h> // Centralized logger_ptr alias

namespace sophia::monte_carlo::models
{
    /**
     * @brief A template base class for implementing the `Action` interface.
     *
     * This class provides a generic implementation of an action, using templates to allow for
     * different types of states and changes. It handles the connection between a source and a target node.
     *
     * @tparam TState The type representing the state of the system (e.g., a board configuration).
     * @tparam TChange The type representing the change that this action applies to a state (e.g., a move).
     */
    template<typename TState, typename TChange>
    class ActionBase : public Action
    {
    protected:
        using node_base_ptr = std::shared_ptr<NodeBase<TState, TChange>>;
        using node_base_ref = std::weak_ptr<NodeBase<TState, TChange>>;
        using const_factory_ptr = std::shared_ptr<const factories::TreeFactoryBase<TState, TChange>>;

    public:
        ActionBase(const node_base_ptr &state, TChange change, const_factory_ptr factory, const sophia::monte_carlo::logger_ptr& logger);

        [[nodiscard]] node_ptr Source() const override;
        [[nodiscard]] node_ptr Target() const override;

    protected:
        /// @brief A factory for creating new nodes in the tree.
        const_factory_ptr m_factory_;

        /// @brief The logger instance for this action.
        logger_ptr m_logger_;

        /// @brief A weak pointer to the source node from which this action originates.
        node_base_ref m_source_;

        /// @brief A shared pointer to the target node that results from this action.
        node_ptr m_target_;

        /// @brief The change in state that this action represents.
        TChange m_change_;
    };
}

#include <monte_carlo/models/action_base.tpp>

#endif //ACTION_BASE_H