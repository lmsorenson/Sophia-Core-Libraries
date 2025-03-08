#include <factories/tic_tac_toe_factory.h>
#include <models/state.h>
#include <models/move.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>
#include <monte_carlo/models/random_action_strategy.h>

using sophia::examples::tic_tac_toe::factories::TicTacToeFactory;
using sophia::examples::tic_tac_toe::models::State;
using sophia::examples::tic_tac_toe::models::Board;
using sophia::examples::tic_tac_toe::models::Position;
using sophia::examples::tic_tac_toe::models::Move;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::models::RolloutStrategyInterface;
using sophia::monte_carlo::models::RandomActionStrategy;
using std::make_shared;
using std::shared_ptr;

shared_ptr<Node> TicTacToeFactory::CreateNode(std::string name) const
{
    return make_shared<State>(name, TileState::X, shared_from_this());
}

shared_ptr<Node> TicTacToeFactory::CreateNode(std::string name, Board board) const
{
    return make_shared<State>(name, board, shared_from_this());
}

shared_ptr<Action> TicTacToeFactory::CreateAction(shared_ptr<NodeBase<Board, Position>> node, Position change) const
{
    return make_shared<Move>(node, change, shared_from_this());
}

shared_ptr<RolloutStrategyInterface> TicTacToeFactory::CreateStrategy() const
{
    return make_shared<RandomActionStrategy>();
}