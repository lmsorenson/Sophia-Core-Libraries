#include <monte_carlo/models/random_rollout_strategy.h>
#include <random>
#include <logging/ilogger.h> // Added include for ILogger

using sophia::monte_carlo::models::RandomRolloutStrategy;
using sophia::monte_carlo::models::Action;
using std::shared_ptr;
using std::vector;
using sophia::logging::logger_ptr; // Added using directive

RandomRolloutStrategy::RandomRolloutStrategy(const logger_ptr& logger)
: m_logger_(logger)
{
}

shared_ptr<Action> RandomRolloutStrategy::select_action(vector<shared_ptr<Action>> actions) const
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


