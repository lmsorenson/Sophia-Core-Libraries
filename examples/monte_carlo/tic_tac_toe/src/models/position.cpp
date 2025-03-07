#include <models/position.h>
#include <models/state.h>
#include <vector>
#include <utility>

using sophia::examples::tic_tac_toe::models::Position;
using std::shared_ptr;
using std::vector;

Position::Position(const std::pair<int, int> &coordinates)
{
    m_row_index_ = coordinates.first;
    m_column_index_ = coordinates.second;
    m_state_ = TileState::E;
}

Position::Position(const std::pair<int, int> &coordinates, const TileState tile_state)
{
    m_row_index_ = coordinates.first;
    m_column_index_ = coordinates.second;
    m_state_ = tile_state;
}

std::pair<int, int> Position::Coordinates() const
{
    return { m_row_index_, m_column_index_ };
}

TileState Position::State() const
{
    return m_state_;
}

Position Position::WithState(TileState new_state) const
{
    auto new_position = *this;

    new_position.m_state_ = new_state;

    return new_position;
}


