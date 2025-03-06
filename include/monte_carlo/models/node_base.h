#ifndef NODE_BASE_H
#define NODE_BASE_H

#include <monte_carlo/models/node.h>

namespace sophia::monte_carlo::factories
{
    template<typename TChange>
    class ITreeFactory;
}

namespace sophia::monte_carlo::models
{
    template<typename TChange>
    class NodeBase : public Node
    {
    public:
        NodeBase(std::string name, std::shared_ptr<const factories::ITreeFactory<TChange>> factory);

    protected:
        std::shared_ptr<ActionSelectStrategyInterface> ActionSelectStrategy() const override;
        std::shared_ptr<const factories::ITreeFactory<TChange>> m_factory_;
    };
}

#include "node_base.tpp"

#endif //NODE_BASE_H
