#include <monte_carlo/models/node_base.h>

using sophia::monte_carlo::models::NodeBase;
using sophia::monte_carlo::models::ActionSelectStrategyInterface;

template<typename TState, typename TChange>
NodeBase<TState, TChange>::NodeBase(const std::string &name, TState state, std::shared_ptr<const factories::ITreeFactory<TState, TChange>> factory)
    : Node(name)
    , m_state_(state)
    , m_factory_(factory)
{
}

template<typename TState, typename TChange>
TState NodeBase<TState, TChange>::GetState() const
{
    return m_state_;
}

template<typename TState, typename TChange>
std::shared_ptr<ActionSelectStrategyInterface> NodeBase<TState, TChange>::ActionSelectStrategy() const
{
    return m_factory_->CreateStrategy();
}
