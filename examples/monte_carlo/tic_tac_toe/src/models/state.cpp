#include <tic_tac_toe/models/state.h>
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

State::State(const string &name, const TileState player, const shared_ptr<const TreeFactoryBase<Board, Position>> &interface)
    : NodeBase(name, Board(player), interface)
{
}

State::State(const std::string &name, Board board,
    const std::shared_ptr<const TreeFactoryBase<Board, Position>> &interface)
: NodeBase(name, std::move(board), interface)
{
}

vector<shared_ptr<Action>> State::GetAvailableActions()
{
    vector<shared_ptr<Action>> actions;

    const auto open_positions = m_state_.GetOpenPositions();
    const auto last_placed = m_state_.LastPlaced();

    const TileState new_state = Alternate(last_placed);

    for(const auto& position : open_positions)
    {
        const auto new_position = position->WithState(new_state);

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
    m_state_.Print();

    const auto player = m_state_.Player();
    if (const auto winner = m_state_.Winner())
    {
        if (winner->first == player)
        {
            std::cout << "Player " << TileStateToString(player) << " wins :)" << std::endl;
            return 1.0;
        }

        std::cout << "Player " << TileStateToString(player) << " loses :(" << std::endl;
        return -1.0;
    }

    std::cout << "It's a draw :/" << std::endl;
    return 0.0;
}

Node::action_ptr State::SelectAction(const std::string action_name)
{
    std::string desired_name = action_name;
    for (char &c : desired_name)
    {
        c = static_cast<char>(std::toupper(c));
    }

    const auto actions = GetAvailableActions();
    std::vector<action_ptr> matching_actions;
    for (const auto& action : actions)
    {
        if (action->Name() == desired_name)
        {
            matching_actions.push_back(action);
        }
    }

    if (matching_actions.size() == 1)
    {
        return matching_actions.front();
    }

    return nullptr;
}

void State::Print() const
{
    m_state_.Print();
}
