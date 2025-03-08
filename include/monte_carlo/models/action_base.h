#ifndef ACTION_BASE_H
#define ACTION_BASE_H

#include <memory>
#include <ostream>

#include <monte_carlo/models/action.h>
#include <monte_carlo/factories/tree_factory_interface.h>

#include "node_base.h"

namespace sophia::monte_carlo::models
{
    template<typename TState, typename TChange>
    class ActionBase : public Action
    {
    protected:
        using node_base_ptr = std::shared_ptr<NodeBase<TState, TChange>>;
        using node_base_ref = std::weak_ptr<NodeBase<TState, TChange>>;
        using const_factory_ptr = std::shared_ptr<const factories::TreeFactoryBase<TState, TChange>>;

    public:
        ActionBase(const node_base_ptr &state, TChange change, const_factory_ptr factory);

        [[nodiscard]] node_ptr Source() const override;
        [[nodiscard]] node_ptr Target() const override;

    protected:
        const_factory_ptr m_factory_;
        node_base_ref m_source_;
        node_ptr m_target_;
        TChange m_change_;
    };
}

#include <monte_carlo/models/action_base.tpp>

#endif //ACTION_BASE_H