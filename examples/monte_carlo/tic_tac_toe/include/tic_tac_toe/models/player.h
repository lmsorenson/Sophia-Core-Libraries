#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <monte_carlo/models/action.h>
#include <tic_tac_toe/enums/symbol.h>

namespace sophia::examples::tic_tac_toe::models
{
    class Player
    {
    public:
        explicit Player(Symbol symbol);
        virtual ~Player() = default;

        [[nodiscard]] Symbol symbol() const;
        [[nodiscard]] virtual std::shared_ptr<monte_carlo::models::Action> GenerateAction(const std::shared_ptr<monte_carlo::models::Node> &node) const = 0;
        [[nodiscard]] double Value(class Board board) const;

    private:
        Symbol m_player_symbol_ = Symbol::None;
    };
}

#endif //PLAYER_H
