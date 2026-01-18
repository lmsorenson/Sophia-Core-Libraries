#include <monte_carlo/models/random_rollout_strategy.h>
#include <random>
#include <monte_carlo/models/action.h> // Required for full definition of Action
#include <monte_carlo/common_aliases.h> // Centralized aliases

using sophia::monte_carlo::models::RandomRolloutStrategy;
// Removed using sophia::monte_carlo::models::Action;
using std::shared_ptr; // Keep as shared_ptr is a standard library type
using std::vector; // Keep as vector is a standard library type
// Removed using sophia::logging::logger_ptr; // Now using sophia::monte_carlo::logger_ptr

RandomRolloutStrategy::RandomRolloutStrategy(const sophia::monte_carlo::logger_ptr& logger)
: m_logger_(logger)
{
}

sophia::monte_carlo::action_ptr RandomRolloutStrategy::select_action(std::vector<sophia::monte_carlo::action_ptr> actions) const
{
    if (actions.empty())
    {
        return nullptr;
    }

    // get random action.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, actions.size() - 1);
    const auto& random_action = actions[dist(gen)];

    if (m_logger_) m_logger_->debug("Rollout selection: {}", random_action->Name());

    return random_action;
}


