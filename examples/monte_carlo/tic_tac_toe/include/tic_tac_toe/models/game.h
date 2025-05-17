#ifndef GAME_H
#define GAME_H
#include <tic_tac_toe/models/board.h>
#include <memory>

namespace sophia::examples::tic_tac_toe::models
{
    class Game
    {
    public:
        Game();
        ~Game();

        template<class TPlayer>
        void Assign(Symbol symbol);

        [[nodiscard]] bool game_over() const;
        [[nodiscard]] const_player_ptr active_player() const;
        void accept_move(Position move);
        void print() const;

    private:
        std::shared_ptr<Player> x_ = nullptr;
        std::shared_ptr<Player> o_ = nullptr;
        std::vector<std::shared_ptr<const Board>> game_states_;
    };

    template<class TPlayer>
    void Game::Assign(Symbol symbol)
    {
        switch (symbol)
        {
            case Symbol::X: x_ = std::make_shared<TPlayer>(symbol); break;
            case Symbol::O: o_ = std::make_shared<TPlayer>(symbol); break;
            default: throw std::invalid_argument("Invalid symbol");
        }
    }
}


#endif //GAME_H
