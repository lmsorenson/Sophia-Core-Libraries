#include <iostream>
#include <models/board.h>
#include <models/position.h>
#include <vector>


using sophia::examples::tic_tac_toe::models::Board;
using sophia::examples::tic_tac_toe::models::Position;
using std::make_shared;
using std::shared_ptr;
using std::vector;


Board::Board()
{
    // for(int row = 0; row < 3; row++)
    // {
    //     vector<Position> row_positions;
    //
    //     for (int col = 0; col < 3; col++)
    //     {
    //         auto new_position = Position({row, col}, TileState::E);
    //         row_positions.push_back(new_position);
    //     }
    //
    //     m_tiles_.push_back(row_positions);
    // }
}

Board::Board(const Board &other)
: m_tiles_(other.m_tiles_)
{
}

Board::Board(Board &&other) noexcept
: m_tiles_(std::move(other.m_tiles_))
{
}

Board & Board::operator=(const Board &other)
{
    if (this == &other)
        return *this;
    m_tiles_ = other.m_tiles_;
    return *this;
}

Board & Board::operator=(Board &&other) noexcept
{
    if (this == &other)
        return *this;
    m_tiles_ = std::move(other.m_tiles_);
    return *this;
}

void Board::SetPosition(const Position &new_position)
{
    if (new_position.State() == TileState::E)
    {
        throw std::invalid_argument("Can't set a position to empty.");
    }

    const auto [row, column] = new_position.Coordinates();

    const auto existing_position = m_tiles_[row][column];

    if (existing_position->State() != TileState::E)
    {
        throw std::invalid_argument("Position already taken.");
    }

    m_tiles_[row][column] = make_shared<Position>((std::pair<int, int>){ row, column }, new_position.State());
}

vector<shared_ptr<const Position>> Board::GetOpenPositions() const
{
    std::vector<shared_ptr<const Position>> open_positions = {};

    for(const auto& row : m_tiles_)
    {
        for (const auto& position : row)
        {
            if (position->State() == TileState::E)
            {
                open_positions.push_back(position);
            }
        }
    }

    return open_positions;
}

shared_ptr<const Board> Board::WithMove(const Position &position) const
{
    try
    {
        Board newBoard = *this;

        newBoard.SetPosition(position);

        return make_shared<Board>(newBoard);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid move exception: " << e.what() << std::endl;
        return nullptr;
    }
}
