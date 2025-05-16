#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <tic_tac_toe/models/position.h>
#include <tic_tac_toe/enums/symbol.h>

namespace sophia::examples::tic_tac_toe::models
{
    class Player
    {
    public:
        explicit Player(Symbol symbol);
        virtual ~Player() = default;

        [[nodiscard]] Symbol symbol() const;
        [[nodiscard]] virtual std::shared_ptr<const Position> NextMove() const = 0;
        [[nodiscard]] double Value(class Board board) const;

    protected:
        Symbol m_player_symbol_ = Symbol::None;
    };
}

#endif //PLAYER_H
