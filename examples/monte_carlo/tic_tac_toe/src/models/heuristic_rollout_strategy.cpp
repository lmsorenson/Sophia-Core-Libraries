#include <tic_tac_toe/models/heuristic_rollout_strategy.h>
#include <tic_tac_toe/models/board.h>
#include <tic_tac_toe/enums/symbol.h>
#include <tic_tac_toe/enums/alignment.h>
#include <monte_carlo/models/action.h>

#include <algorithm>
#include <limits>

using sophia::monte_carlo::tic_tac_toe::models::HeuristicRolloutStrategy;
using sophia::monte_carlo::models::Action;


HeuristicRolloutStrategy::HeuristicRolloutStrategy(GameState current_game_state, const logger_ptr& logger)
    : m_current_game_state(std::move(current_game_state)), m_logger(logger)
{
}

std::shared_ptr<Action> HeuristicRolloutStrategy::select_action(
    std::vector<action_ptr> actions) const
{
    return actions[0];
}
