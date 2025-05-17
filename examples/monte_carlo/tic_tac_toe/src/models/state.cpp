#include <tic_tac_toe/models/state.h>
#include <monte_carlo/factories/tree_factory_interface.h>

#include <utility>
#include <tic_tac_toe/models/bot.h>
#include <tic_tac_toe/models/human.h>

using sophia::examples::tic_tac_toe::models::State;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using std::shared_ptr;
using std::vector;
using std::string;

Symbol Alternate(const Symbol last_placed)
{
    switch (last_placed)
    {
        case Symbol::X: return Symbol::O;
        case Symbol::O:
        default:
        case Symbol::None: return Symbol::X;
    }
}

State::State(const string &name, const shared_ptr<const TreeFactoryBase<GameState, Position>> &interface)
    : NodeBase(name, GameState(nullptr, nullptr), interface)
{
}

State::State(const std::string &name, GameState game_state,
    const std::shared_ptr<const TreeFactoryBase<GameState, Position>> &interface)
: NodeBase(name, std::move(game_state), interface)
{
}

vector<shared_ptr<Action>> State::GetAvailableActions()
{
    vector<shared_ptr<Action>> actions;

    const auto open_positions = m_state_.GetOpenPositions();
    const auto last_placed = m_state_.LastPlaced();

    const Symbol new_state = Alternate(last_placed);

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
    const auto board = m_state_.GetBoard();

    const auto you = m_state_.You();

    return you->Value(board);
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
