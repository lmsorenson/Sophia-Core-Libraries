#include <models/state.h>
#include <monte_carlo/factories/tree_factory_interface.h>

#include <utility>

using sophia::examples::tic_tac_toe::models::State;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using std::shared_ptr;
using std::vector;
using std::string;

State::State(const string &name, const shared_ptr<const ITreeFactory<Board, Position>> &interface)
    : NodeBase(name, interface)
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

    auto open_positions = m_state_.GetOpenPositions();

    for(const auto& position : open_positions)
    {
        auto _this_ = std::static_pointer_cast<State>(shared_from_this());
        auto action = m_factory_->CreateAction(_this_, *position);
        actions.push_back(action);
    }

    return actions;
}

bool State::IsTerminalState() const
{
    const auto list = {
        m_state_.GetRow(LineType::Horizontal),
        m_state_.GetRow(LineType::Vertical),
        m_state_.GetRow(LineType::Diagonal)
    };

    for(const auto& line_type : list)
    {
        for(const auto& line : line_type)
        {
            auto tile_state = TileState::E;
            bool completed = true;
            for(const auto& position : line)
            {
                // if there is ever a position that is empty.
                // the line is not complete.
                if (position == TileState::E)
                {
                    completed = false;
                    break;
                }

                // to start it will be empty.
                // seed it with the first value.
                if (tile_state == TileState::E)
                {
                    tile_state = position;
                }

                if (position != tile_state)
                {
                    completed = false;
                    break;
                }
            }
            return completed;
        }
    }

    return false;
}

double State::Value() const
{
    double score = 0.0;

    return score;
}