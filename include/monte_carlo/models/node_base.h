#ifndef NODE_BASE_H
#define NODE_BASE_H

#include <monte_carlo/models/node.h>

namespace sophia::monte_carlo::factories
{
    template<typename TState, typename TChange>
    class ITreeFactory;
}

namespace sophia::monte_carlo::models
{
    template<typename TState, typename TChange>
    class NodeBase : public Node
    {
    public:
        NodeBase(std::string name, std::shared_ptr<const factories::ITreeFactory<TState, TChange>> factory);
        NodeBase(std::string name, TState state, std::shared_ptr<const factories::ITreeFactory<TState, TChange>> factory);

        TState GetState() const;

    protected:
        std::shared_ptr<ActionSelectStrategyInterface> ActionSelectStrategy() const override;
        std::shared_ptr<const factories::ITreeFactory<TState, TChange>> m_factory_;
        TState m_state_;
    };
}

#include "node_base.tpp"

#endif //NODE_BASE_H
