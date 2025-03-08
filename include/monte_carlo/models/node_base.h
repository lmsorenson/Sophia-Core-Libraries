#ifndef NODE_BASE_H
#define NODE_BASE_H

#include <monte_carlo/models/node.h>
#include <monte_carlo/factories/tree_factory_interface.h>

namespace sophia::monte_carlo::models
{
    template<typename TState, typename TChange>
    class NodeBase : public Node
    {
    protected:
        using const_factory_ptr = std::shared_ptr<const factories::ITreeFactory<TState, TChange>>;

    public:
        NodeBase(const std::string &name, TState state, const_factory_ptr factory);

        TState GetState() const;

    protected:
        rollout_strategy_ptr RolloutStrategy() const override;
        const_factory_ptr m_factory_;
        TState m_state_;
    };
}

#include <monte_carlo/models/node_base.tpp>

#endif //NODE_BASE_H
