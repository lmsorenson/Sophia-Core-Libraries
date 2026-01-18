#include <monte_carlo/models/action_base.h>
#include <monte_carlo/common_aliases.h> // Centralized aliases

namespace sophia::monte_carlo::models
{
// Removed using sophia::monte_carlo::models::ActionBase;
// Removed using sophia::monte_carlo::models::Node;
// Removed using sophia::monte_carlo::models::RolloutStrategyInterface;
// Removed using sophia::monte_carlo::node_ptr;

template<typename TState, typename TChange>
ActionBase<TState, TChange>::ActionBase(const sophia::monte_carlo::node_base_ptr<TState, TChange> &state, TChange change, sophia::monte_carlo::const_factory_ptr<TState, TChange> factory, const sophia::monte_carlo::logger_ptr& logger)
    : Action()
    , m_source_(state)
    , m_change_(change)
    , m_factory_(factory)
    , m_logger_(logger)
{
}

template<typename TState, typename TChange>
sophia::monte_carlo::node_ptr ActionBase<TState, TChange>::Source() const
{
    return m_source_.lock();
}

template<typename TState, typename TChange>
sophia::monte_carlo::node_ptr ActionBase<TState, TChange>::Target() const
{
    return m_target_;
}
} // namespace sophia::monte_carlo::models