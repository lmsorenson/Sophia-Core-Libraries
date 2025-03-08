#include <monte_carlo/models/random_rollout_strategy.h>
#include <random>

using sophia::monte_carlo::models::RandomRolloutStrategy;
using sophia::monte_carlo::models::Action;
using std::shared_ptr;
using std::vector;

shared_ptr<const Action> RandomRolloutStrategy::select_action(const vector<shared_ptr<const Action>> actions) const
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

    return random_action;
}


