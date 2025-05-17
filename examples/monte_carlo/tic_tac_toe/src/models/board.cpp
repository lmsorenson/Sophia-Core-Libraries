#include <tic_tac_toe/models/board.h>
#include <tic_tac_toe/models/position.h>
#include <unordered_set>
#include <iostream>
#include <vector>


using sophia::examples::tic_tac_toe::models::Board;
using sophia::examples::tic_tac_toe::models::Position;
using sophia::examples::tic_tac_toe::models::Player;
using sophia::examples::tic_tac_toe::models::player_ptr;
using std::make_shared;
using std::shared_ptr;
using std::vector;
using std::pair;


Board::Board()
{
    for(int row = 0; row < 3; row++)
    {
        vector<shared_ptr<const Position>> row_positions;

        for (int col = 0; col < 3; col++)
        {
            auto new_position = make_shared<Position>(std::pair(row, col), Symbol::None);
            row_positions.push_back(new_position);
        }

        m_tiles_.push_back(row_positions);
    }
}

Board::Board(const Board &other)
: m_tiles_(other.m_tiles_)
, last_placed_(other.last_placed_)
{
}

Board::Board(Board &&other) noexcept
: m_tiles_(std::move(other.m_tiles_))
, last_placed_(other.last_placed_)
{
}

Board & Board::operator=(const Board &other)
{
    if (this == &other)
        return *this;
    m_tiles_ = other.m_tiles_;
    last_placed_ = other.last_placed_;
    return *this;
}

Board & Board::operator=(Board &&other) noexcept
{
    if (this == &other)
        return *this;
    m_tiles_ = std::move(other.m_tiles_);
    last_placed_ = other.last_placed_;
    return *this;
}

void Board::SetPosition(const Position &new_position)
{
    if (new_position.State() == Symbol::None)
    {
        throw std::invalid_argument("Can't set a position to empty.");
    }

    const auto [row, column] = new_position.Coordinates();

    const auto existing_position = m_tiles_[row][column];

    if (existing_position->State() != Symbol::None)
    {
        throw std::invalid_argument("Position already taken.");
    }

    auto placed_state = new_position.State();
    m_tiles_[row][column] = make_shared<Position>(std::pair( row, column ), placed_state);
    last_placed_ = placed_state;
}

Symbol Board::LastPlaced() const
{
    return last_placed_;
}

vector<shared_ptr<const Position>> Board::GetOpenPositions() const
{
    std::vector<shared_ptr<const Position>> open_positions = {};

    for(const auto& row : m_tiles_)
    {
        for (const auto& position : row)
        {
            if (position->State() == Symbol::None)
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

shared_ptr<std::pair<Symbol, bool>> Board::Winner() const
{
    const auto list = {
        GetRow(LineType::Horizontal),
        GetRow(LineType::Vertical),
        GetRow(LineType::Diagonal)
    };

    for(const auto& line_type : list)
    {
        for(auto line : line_type)
        {
            std::unordered_set unique_set(line.begin(), line.end());
            std::vector unique_vec(unique_set.begin(), unique_set.end());
            if (unique_vec.size() == 1 && unique_vec.front() != Symbol::None)
            {
                return std::make_shared<std::pair<Symbol, bool>>(unique_vec.front(), true);
            }
        }
    }
    return nullptr;
}

void Board::Print() const
{
    std::vector<std::string> rows_strings;
    auto column_letter = { "A", "B", "C" };
    auto itr = column_letter.begin();

    for (const auto& row : m_tiles_)
    {
        std::string row_str;
        for (const auto& position : row)
        {
            if (!row_str.empty())
            {
                row_str.append("|");
            }
            else
            {
                row_str.append(" ");
                row_str.append(*itr);
                row_str.append(" ");
                itr++;
            }

            row_str.append(" ");
            row_str.append(TileStateToString(position->State()));
            row_str.append(" ");
        }

        rows_strings.push_back(row_str);
    }

    if (auto it = rows_strings.begin(); it != rows_strings.end())
    {
        std::cout << "    1   2   3 " << std::endl;
        do
        {
            std::cout << *it << std::endl;
            if (it++ + 1 != rows_strings.end())
            {
                std::cout << "   ---+---+---" << std::endl;
            }
        }
        while (it != rows_strings.end());
    }
}

std::vector<std::vector<Symbol>> Board::GetRow(LineType line_type) const
{
    switch (line_type)
    {
        case LineType::Horizontal:
            return {
                {
                    m_tiles_[0][0]->State(),
                    m_tiles_[0][1]->State(),
                    m_tiles_[0][2]->State()
                },
                {
                    m_tiles_[1][0]->State(),
                    m_tiles_[1][1]->State(),
                    m_tiles_[1][2]->State()
                },
                {
                    m_tiles_[2][0]->State(),
                    m_tiles_[2][1]->State(),
                    m_tiles_[2][2]->State()
                }
            };
        case LineType::Vertical:
            return {
                    {
                        m_tiles_[0][0]->State(),
                        m_tiles_[1][0]->State(),
                        m_tiles_[2][0]->State()
                    },
                    {
                        m_tiles_[0][1]->State(),
                        m_tiles_[1][1]->State(),
                        m_tiles_[2][1]->State()
                    },
                    {
                        m_tiles_[0][2]->State(),
                        m_tiles_[1][2]->State(),
                        m_tiles_[2][2]->State()
                    },
                };
        case LineType::Diagonal:
            return {
                    {
                        m_tiles_[0][0]->State(),
                        m_tiles_[1][1]->State(),
                        m_tiles_[2][2]->State()
                    },
                    {
                        m_tiles_[2][0]->State(),
                        m_tiles_[1][1]->State(),
                        m_tiles_[0][2]->State()
                    }
                };
        default: return {};
    }
}
