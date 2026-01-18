#include <monte_carlo/models/node_base.h>
#include <monte_carlo/common_aliases.h> // Centralized aliases

namespace sophia::monte_carlo::models
{
// Removed using sophia::monte_carlo::models::NodeBase;
// Removed using sophia::monte_carlo::models::RolloutStrategyInterface;
// Removed using rollout_strategy_ptr = std::shared_ptr<RolloutStrategyInterface>;

template<typename TState, typename TChange>
NodeBase<TState, TChange>::NodeBase(const std::string &name, TState state, sophia::monte_carlo::const_factory_ptr<TState, TChange> factory, const sophia::monte_carlo::logger_ptr& logger)
    : Node(name, logger)
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
sophia::monte_carlo::rollout_strategy_ptr NodeBase<TState, TChange>::RolloutStrategy() const
{
    return m_factory_->CreateStrategy();
}
} // namespace sophia::monte_carlo::models
