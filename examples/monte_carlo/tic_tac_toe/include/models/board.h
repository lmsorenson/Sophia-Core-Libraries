#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <vector>
#include <models/position.h>
#include <memory>

namespace sophia::examples::tic_tac_toe::models
{
    class Position;

    class Board
    {
    public:
        Board();
        Board(const Board &other);
        Board(Board &&other) noexcept;
        Board & operator=(const Board &other);
        Board & operator=(Board &&other) noexcept;

        void SetPosition(const Position &new_position);
        [[nodiscard]] std::vector<std::shared_ptr<const Position>> GetOpenPositions() const;
        [[nodiscard]] std::shared_ptr<const Board> WithMove(const Position& position) const;

    private:
        std::vector<std::vector<std::shared_ptr<const Position>>> m_tiles_;
    };
}

#endif //TIC_TAC_TOE_BOARD_H
