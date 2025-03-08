#include <monte_carlo/models/action_base.h>

using sophia::monte_carlo::models::ActionBase;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::ActionSelectStrategyInterface;

template<typename TState, typename TChange>
ActionBase<TState, TChange>::ActionBase(const std::shared_ptr<NodeBase<TState, TChange>> &state, TChange change,
    std::shared_ptr<const factories::ITreeFactory<TState, TChange>> factory)
    : Action()
    , m_source_(state)
    , m_change_(change)
    , m_factory_(factory)
{
}

template<typename TState, typename TChange>
std::shared_ptr<Node> ActionBase<TState, TChange>::Source() const
{
    return m_source_.lock();
}