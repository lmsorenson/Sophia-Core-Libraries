#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <tic_tac_toe/models/position.h>
#include <tic_tac_toe/enums/symbol.h>
#include <tic_tac_toe/observer/observer.h>

namespace sophia::monte_carlo::tic_tac_toe::models
{
    /**
     * @class Player
     * @brief A Player in a Tic Tac Toe Game
     */
    class Player : public std::enable_shared_from_this<Player>, public observer::Observer
    {
    public:
        explicit Player(enums::Symbol symbol);
        virtual ~Player() = default;

        [[nodiscard]] enums::Symbol symbol() const;
        [[nodiscard]] virtual std::shared_ptr<const Position> NextMove() const = 0;
        [[nodiscard]] double Value(class Board board) const;

    protected:
        enums::Symbol m_player_symbol_ = enums::Symbol::None;
    };
}

#endif //PLAYER_H
