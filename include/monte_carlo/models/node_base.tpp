#include <monte_carlo/models/node_base.h>

using sophia::monte_carlo::models::NodeBase;
using sophia::monte_carlo::models::ActionSelectStrategyInterface;

template<typename TChange>
NodeBase<TChange>::NodeBase(std::string name, std::shared_ptr<const factories::ITreeFactory<TChange>> factory)
: Node(name)
, m_factory_(factory)
{
}

template<typename TChange>
std::shared_ptr<ActionSelectStrategyInterface> NodeBase<TChange>::ActionSelectStrategy() const
{
    return m_factory_->CreateStrategy();
}