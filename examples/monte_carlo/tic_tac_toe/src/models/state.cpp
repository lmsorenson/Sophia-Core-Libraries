#include <models/state.h>
#include <monte_carlo/factories/tree_factory_interface.h>

#include <utility>

using sophia::examples::tic_tac_toe::models::State;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using std::shared_ptr;
using std::vector;
using std::string;

TileState Alternate(const TileState last_placed)
{
    switch (last_placed)
    {
        case TileState::X: return TileState::O;
        case TileState::O:
        default:
        case TileState::E: return TileState::X;
    }
}

State::State(const string &name, const TileState player, const shared_ptr<const ITreeFactory<Board, Position>> &interface)
    : NodeBase(name, Board(player), interface)
{
}

State::State(const std::string &name, Board board,
    const std::shared_ptr<const ITreeFactory<Board, Position>> &interface)
: NodeBase(name, std::move(board), interface)
{
}

vector<shared_ptr<Action>> State::GetAvailableActions()
{
    vector<shared_ptr<Action>> actions;

    const auto open_positions = m_state_.GetOpenPositions();
    const auto last_placed = m_state_.LastPlaced();

    TileState new_state = Alternate(last_placed);

    for(const auto& position : open_positions)
    {
        auto new_position = position->WithState(new_state);

        auto _this_ = std::static_pointer_cast<State>(shared_from_this());
        auto action = m_factory_->CreateAction(_this_, new_position);
        action->Generate();
        actions.push_back(action);
    }

    return actions;
}

bool State::IsTerminalState() const
{
    if (m_state_.GetOpenPositions().empty())
        return true;

    if (auto winner = m_state_.Winner())
    {
        return true;
    }

    return false;
}

double State::Value() const
{
    auto player = m_state_.Player();
    std::cout << "Player " << TileStateToString(player) << std::endl;

    if (auto winner = m_state_.Winner())
    {
        if (winner->first == player)
            return 1.0;
        else
            return -1.0;
    }
    
    return 0.0;
}
