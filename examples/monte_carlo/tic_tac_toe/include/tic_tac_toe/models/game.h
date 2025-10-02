#ifndef GAME_H
#define GAME_H
#include <tic_tac_toe/models/board.h>
#include <tic_tac_toe/observer/subject.h>
#include <memory>
#include <stdexcept>

namespace sophia::examples::tic_tac_toe::models
{
    /**
     * @class Game
     * @brief A Tic Tac Toe game.
     */
    class Game : observer::Subject
    {
    public:
        Game();
        ~Game();

        /**
         * @brief Assigns a particular type of player to a symbol.
         * @tparam TPlayer The type of player to be assigned.  (Probably a Human or a Bot)
         * @tparam Args Constructor arguments for the Player.
         * @param symbol The symbol in which the new player will occupy.
         * @param args The constructor argument values for the Player.
         * @throws invalid_argument if the Symbol is not valid.
         */
        template<class TPlayer, typename... Args>
        void Assign(Symbol symbol, Args... args);

        /**
         * @brief Is the game over?
         * @return A boolean value: true if the game is over, false if it is not.
         */
        [[nodiscard]] bool game_over() const;

        /**
         * @brief Gets the current active player.
         * @return A shared pointer to the active player of the game.
         */
        [[nodiscard]] const_player_ptr active_player() const;

        /**
         * Applies a move to the Tic Tac Toe game.
         * @param move The move being applied.
         */
        void accept_move(Position move);

        /**
         * Prints the Tic Tac Toe game to the console.
         */
        void print() const;

    private:
        std::shared_ptr<Player> x_ = nullptr;
        std::shared_ptr<Player> o_ = nullptr;
        std::vector<std::shared_ptr<const Board>> game_states_;

    };

    template<class TPlayer, typename... Args>
    void Game::Assign(Symbol symbol, Args ... args)
    {
        switch (symbol)
        {
            case Symbol::X:
                x_ = std::make_shared<TPlayer>(symbol, args...);
                add_observer(x_);
                break;
            case Symbol::O:
                o_ = std::make_shared<TPlayer>(symbol, args...);
                add_observer(o_);
                break;
            default: throw std::invalid_argument("Invalid symbol");
        }
    }
}


#endif //GAME_H
