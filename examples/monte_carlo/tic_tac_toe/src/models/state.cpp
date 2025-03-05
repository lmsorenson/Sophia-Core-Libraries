#include <models/state.h>

using sophia::examples::tic_tac_toe::models::State;
using sophia::monte_carlo::models::Node;
using std::shared_ptr;
using std::vector;
using std::string;

State::State(const string &name, const shared_ptr<const ITreeFactory> &interface)
    : Node(name, interface)
{
}

vector<shared_ptr<Node>> State::GetAvailableActions() const
{
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