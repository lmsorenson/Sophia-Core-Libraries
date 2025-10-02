#ifndef POSITION_H
#define POSITION_H

#include <utility>
#include <tic_tac_toe/enums/symbol.h>

namespace sophia::examples::tic_tac_toe::models
{
    /**
     * @class Position
     * @brief Refers to a move that a Player can make in a Tic Tac Toe Game.
     * A position can be empty, it can have an X Symbol, or it can have an O Symbol.
     */
    class Position
    {
    public:
        explicit Position(const std::pair<int, int> &coordinates);
        Position(const std::pair<int, int> &coordinates, enums::Symbol tile_state);

        [[nodiscard]] std::string Name() const;
        [[nodiscard]] std::pair<int, int> Coordinates() const;
        [[nodiscard]] enums::Symbol State() const;
        [[nodiscard]] Position WithState(enums::Symbol new_state) const;

        static std::pair<int,int> parse_move(const std::string &input);
        static bool is_valid(const std::string &input);

    private:
        int m_row_index_ = 0;
        int m_column_index_ = 0;
        enums::Symbol m_state_ = enums::Symbol::None;
    };
}

#endif //POSITION_H