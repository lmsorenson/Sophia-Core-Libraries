#include <monte_carlo/models/node_base.h>

using sophia::monte_carlo::models::NodeBase;
using sophia::monte_carlo::models::RolloutStrategyInterface;
using rollout_strategy_ptr = std::shared_ptr<RolloutStrategyInterface>;

template<typename TState, typename TChange>
NodeBase<TState, TChange>::NodeBase(const std::string &name, TState state, const_factory_ptr factory, const logger_ptr& logger)
    : Node(name, logger) // Pass logger to base Node constructor
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
rollout_strategy_ptr NodeBase<TState, TChange>::RolloutStrategy() const
{
    return m_factory_->CreateStrategy();
}
