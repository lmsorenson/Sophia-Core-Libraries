#include <factories/tic_tac_toe_factory.h>
#include <models/state.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>
#include <monte_carlo/models/random_action_strategy.h>

using sophia::examples::tic_tac_toe::factories::TicTacToeFactory;
using sophia::examples::tic_tac_toe::models::State;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::models::ActionSelectStrategyInterface;
using sophia::monte_carlo::models::RandomActionStrategy;
using std::make_shared;
using std::shared_ptr;

shared_ptr<Node> TicTacToeFactory::CreateNode(std::string name) const
{
    return make_shared<State>(name, shared_from_this());
}

shared_ptr<Action> TicTacToeFactory::CreateAction(shared_ptr<Node> parent, shared_ptr<Node> child) const
{
    return make_shared<Action>(parent, child);
}

shared_ptr<ActionSelectStrategyInterface> TicTacToeFactory::CreateStrategy() const
{
    return make_shared<RandomActionStrategy>();
}