#include <models/state.h>
#include <monte_carlo/factories/tree_factory_interface.h>

using sophia::examples::tic_tac_toe::models::State;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using std::shared_ptr;
using std::vector;
using std::string;

State::State(const string &name, const shared_ptr<const ITreeFactory> &interface)
    : Node(name, interface)
{
}

vector<shared_ptr<Action>> State::GetAvailableActions() const
{
    auto open_positions = m_board_.GetOpenPositions();

    // todo - essentially you want to create a list of actions from these position moves,
    // todo - but these positions are specific to tic_tac_toe so we don't want the factory
    // todo - to have knowledge of tic tac toe positions.
    auto action = m_factory_->CreateAction(nullptr);

    return {};
}

bool State::IsTerminalState() const
{
    return false;
}

double State::Value() const
{
    return 0.0;
}