#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <vector>
#include <tic_tac_toe/models/player.h>
#include <tic_tac_toe/models/position.h>
#include <tic_tac_toe/enums/line_type.h>
#include <memory>



namespace sophia::examples::tic_tac_toe::models
{
    class Position;
    using player_ptr = std::shared_ptr<Player>;
    using const_player_ptr = std::shared_ptr<const Player>;

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
        [[nodiscard]] std::vector<std::vector<Symbol>> GetRow(LineType line_type) const;
        [[nodiscard]] std::shared_ptr<std::pair<Symbol, bool>> Winner() const;
        void Print() const;

    private:
        std::vector<std::vector<std::shared_ptr<const Position>>> m_tiles_;
    };
}

#endif //TIC_TAC_TOE_BOARD_H
