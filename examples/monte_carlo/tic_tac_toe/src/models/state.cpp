#include <tic_tac_toe/models/state.h>
#include <monte_carlo/factories/tree_factory_interface.h>

#include <utility>
#include <tic_tac_toe/models/bot.h>
#include <tic_tac_toe/models/human.h>

using sophia::monte_carlo::tic_tac_toe::models::State;
using sophia::monte_carlo::tic_tac_toe::enums::Symbol;
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

State::State(const string &name, const shared_ptr<const TreeFactoryBase<GameState, Position>> &tree_factory, const logger_ptr& logger)
    : NodeBase(name, GameState(nullptr, nullptr), tree_factory, logger)
{
}

State::State(const std::string &name, GameState game_state,
    const std::shared_ptr<const TreeFactoryBase<GameState, Position>> &tree_factory, const logger_ptr& logger)
: NodeBase(name, std::move(game_state), tree_factory, logger)
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

    // 1. First, check if the action exists in already expanded children (m_child_action_)
    for (const auto& existing_child_action : m_child_action_)
    {
        if (existing_child_action->Name() == desired_name)
        {
            if (m_logger_) m_logger_->debug("SelectAction: Found existing child action '{}'. Reusing.", desired_name);
            return existing_child_action;
        }
    }

    // 2. If not found in existing children, generate all possible actions for the current state.
    //    These will be new action/node pairs.
    const vector<action_ptr> newly_generated_actions = GetAvailableActions();

    for (const auto& new_action : newly_generated_actions)
    {
        if (new_action->Name() == desired_name)
        {
            if (m_logger_) m_logger_->debug("SelectAction: Generated new action '{}'. Adding to children and returning.", desired_name);
            // Add this newly generated action to our m_child_action_ list for future reuse
            m_child_action_.push_back(new_action);
            if (new_action->Target()) {
                new_action->Target()->SetParent(new_action);
            }
            return new_action;
        }
    }

    if (m_logger_) m_logger_->warn("SelectAction: No matching action found for name '{}'.", desired_name);
    return nullptr;
}

void State::Print() const
{
    m_state_.Print();
}
