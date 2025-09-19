#ifndef POSITION_H
#define POSITION_H

#include <utility>
#include <tic_tac_toe/enums/symbol.h>

namespace sophia::examples::tic_tac_toe::models
{
    class Position
    {
    public:
        explicit Position(const std::pair<int, int> &coordinates);
        Position(const std::pair<int, int> &coordinates, Symbol tile_state);

        [[nodiscard]] std::string Name() const;
        [[nodiscard]] std::pair<int, int> Coordinates() const;
        [[nodiscard]] Symbol State() const;
        [[nodiscard]] Position WithState(Symbol new_state) const;

        static std::pair<int,int> parse_move(const std::string &input);
        static bool is_valid(const std::string &input);

    private:
        int m_row_index_ = 0;
        int m_column_index_ = 0;
        Symbol m_state_ = Symbol::None;
    };
}

#endif //POSITION_H