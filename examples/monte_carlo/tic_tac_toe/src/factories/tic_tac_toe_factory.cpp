#include <tic_tac_toe/factories/tic_tac_toe_factory.h>
#include <tic_tac_toe/models/state.h>
#include <tic_tac_toe/models/move.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>
#include <monte_carlo/models/random_rollout_strategy.h>
#include <tic_tac_toe/models/bot.h>
#include <tic_tac_toe/models/human.h>

using sophia::examples::tic_tac_toe::factories::TicTacToeFactory;
using sophia::examples::tic_tac_toe::models::State;
using sophia::examples::tic_tac_toe::models::Board;
using sophia::examples::tic_tac_toe::models::GameState;
using sophia::examples::tic_tac_toe::models::Position;
using sophia::examples::tic_tac_toe::models::Move;
using sophia::examples::tic_tac_toe::models::Human;
using sophia::examples::tic_tac_toe::models::Bot;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::models::RolloutStrategyInterface;
using sophia::monte_carlo::models::RandomRolloutStrategy;
using std::make_shared;
using std::shared_ptr;

shared_ptr<Node> TicTacToeFactory::CreateNode(std::string name) const
{
    auto x = make_shared<Bot>(Symbol::X);
    auto o = make_shared<Human>(Symbol::O);
    auto board = make_shared<Board>();
    auto game_state = make_shared<GameState>(x, o, board);

    return make_shared<State>(name, *game_state, shared_from_this());
}

shared_ptr<Node> TicTacToeFactory::CreateNode(std::string name, models::GameState game_state) const
{
    return make_shared<State>(name, game_state, shared_from_this());
}

shared_ptr<Action> TicTacToeFactory::CreateAction(shared_ptr<NodeBase<GameState, Position>> node, Position change) const
{
    return make_shared<Move>(node, change, shared_from_this());
}

shared_ptr<RolloutStrategyInterface> TicTacToeFactory::CreateStrategy() const
{
    return make_shared<RandomRolloutStrategy>();
}