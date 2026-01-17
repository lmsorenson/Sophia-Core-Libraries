#include <monte_carlo/models/action_base.h>

using sophia::monte_carlo::models::ActionBase;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::RolloutStrategyInterface;
using node_ptr = std::shared_ptr<Node>;

template<typename TState, typename TChange>
ActionBase<TState, TChange>::ActionBase(const node_base_ptr &state, TChange change, const_factory_ptr factory, const logger_ptr& logger)
    : Action()
    , m_source_(state)
    , m_change_(change)
    , m_factory_(factory)
    , m_logger_(logger)
{
}

template<typename TState, typename TChange>
node_ptr ActionBase<TState, TChange>::Source() const
{
    return m_source_.lock();
}

template<typename TState, typename TChange>
node_ptr ActionBase<TState, TChange>::Target() const
{
    return m_target_;
}