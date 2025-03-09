#ifndef POSITION_H
#define POSITION_H

#include <utility>
#include <tic_tac_toe/enums/tile_state.h>

namespace sophia::examples::tic_tac_toe::models
{
    class Position
    {
    public:
        explicit Position(const std::pair<int, int> &coordinates);
        Position(const std::pair<int, int> &coordinates, TileState tile_state);

        [[nodiscard]] std::string Name() const;
        [[nodiscard]] std::pair<int, int> Coordinates() const;
        [[nodiscard]] TileState State() const;
        Position WithState(TileState new_state) const;

    private:
        int m_row_index_ = 0;
        int m_column_index_ = 0;
        TileState m_state_ = TileState::E;
    };
}

#endif //POSITION_H