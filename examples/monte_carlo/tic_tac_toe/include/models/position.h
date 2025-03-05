#ifndef POSITION_H
#define POSITION_H

#include <utility>
#include <enums/tile_state.h>

namespace sophia::examples::tic_tac_toe::models
{
    class Position
    {
    public:
        explicit Position(const std::pair<int, int> &coordinates);
        Position(const std::pair<int, int> &coordinates, TileState tile_state);

        [[nodiscard]] std::pair<int, int> Coordinates() const;
        [[nodiscard]] TileState State() const;

    private:
        int m_row_index_ = 0;
        int m_column_index_ = 0;
        TileState m_state_ = TileState::E;
    };
}

#endif //POSITION_H