#include <tic_tac_toe/factories/tic_tac_toe_factory.h>
#include <tic_tac_toe/models/state.h>
#include <tic_tac_toe/models/move.h>
#include <monte_carlo/models/random_rollout_strategy.h> // Need concrete strategy for CreateStrategy()

#include <utility>
#include <monte_carlo/common_aliases.h> // Centralized aliases

using sophia::monte_carlo::tic_tac_toe::factories::TicTacToeFactory;
using sophia::monte_carlo::tic_tac_toe::models::State;
using sophia::monte_carlo::tic_tac_toe::models::Board;
using sophia::monte_carlo::tic_tac_toe::models::GameState;
using sophia::monte_carlo::tic_tac_toe::models::Position;
using sophia::monte_carlo::tic_tac_toe::models::Move;
// Removed using sophia::monte_carlo::models::Node;
// Removed using sophia::monte_carlo::models::Action;
// Removed using sophia::monte_carlo::models::RolloutStrategyInterface;
using sophia::monte_carlo::models::RandomRolloutStrategy; // Keep using for concrete class
using std::make_shared;
using std::shared_ptr; // Keep for standard library type

TicTacToeFactory::TicTacToeFactory(models::const_player_ptr you, const sophia::monte_carlo::logger_ptr& logger)
: you_(std::move(you))
, m_logger_(logger)
{
}

sophia::monte_carlo::node_ptr TicTacToeFactory::CreateNode(std::string name) const
{
    auto board = make_shared<Board>(m_logger_); // Pass m_logger_ to Board constructor
    const auto game_state = make_shared<GameState>(you_, board);

    return std::static_pointer_cast<sophia::monte_carlo::models::Node>(make_shared<State>(name, *game_state, shared_from_this(), m_logger_));
}

sophia::monte_carlo::node_ptr TicTacToeFactory::CreateNode(std::string name, GameState game_state) const
{
    return std::static_pointer_cast<sophia::monte_carlo::models::Node>(make_shared<State>(name, game_state, shared_from_this(), m_logger_));
}

sophia::monte_carlo::action_ptr TicTacToeFactory::CreateAction(sophia::monte_carlo::node_base_ptr<GameState, Position> node, Position change) const
{
    return make_shared<Move>(node, change, shared_from_this(), m_logger_);
}

sophia::monte_carlo::rollout_strategy_ptr TicTacToeFactory::CreateStrategy() const
{
    return make_shared<RandomRolloutStrategy>(m_logger_);
}