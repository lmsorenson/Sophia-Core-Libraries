#ifndef GAME_H
#define GAME_H
#include <tic_tac_toe/models/board.h>
#include <tic_tac_toe/observer/subject.h>
#include <memory>
#include <stdexcept>

namespace sophia::monte_carlo::tic_tac_toe::models
{
    /**
     * @class Game
     * @brief A Tic Tac Toe game.
     */
    class Game : observer::Subject
    {
    public:
        /**
         * @brief Constructs a new Game with default settings.
         */
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
        void Assign(enums::Symbol symbol, Args... args);

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
         * @brief Applies a move to the Tic Tac Toe game.
         * @param move The move being applied.
         */
        void accept_move(Position move);

        /**
         * @brief Prints the Tic Tac Toe game to the console.
         */
        void print() const;

    private:
        /**
         * @brief The player controlling the X positions.
         */
        std::shared_ptr<Player> x_ = nullptr;

        /**
         * @brief The player controlling the Y positions.
         */
        std::shared_ptr<Player> o_ = nullptr;

        /**
         * @brief A list of boards.  A board represents a state of play.
         * This list should be ordered.  A Tic Tac Toe game will have 9 states at most.
         */
        std::vector<std::shared_ptr<const Board>> game_states_;
    };

    template<class TPlayer, typename... Args>
    void Game::Assign(enums::Symbol symbol, Args ... args)
    {
        switch (symbol)
        {
            case enums::Symbol::X:
                x_ = std::make_shared<TPlayer>(symbol, args...);
                add_observer(x_);
                break;
            case enums::Symbol::O:
                o_ = std::make_shared<TPlayer>(symbol, args...);
                add_observer(o_);
                break;
            default: throw std::invalid_argument("Invalid symbol");
        }
    }
}


#endif //GAME_H
