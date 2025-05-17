#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <memory>

#include <tic_tac_toe/models/board.h>

namespace sophia::examples::tic_tac_toe::models
{
    /// A state refers to the state from one player's perspective.
    /// This is for the monte carlo engine.
    class GameState
    {
    public:
        explicit GameState(const_player_ptr you, std::shared_ptr<const Board> board);
        explicit GameState(const_player_ptr you, std::shared_ptr<const Board> board, Symbol last_placed);

        [[nodiscard]] std::shared_ptr<const GameState> ApplyMove(const Position& position) const;
        [[nodiscard]] std::shared_ptr<const Player> CurrentPlayer() const;
        [[nodiscard]] std::shared_ptr<const Player> You() const;
        [[nodiscard]] std::shared_ptr<std::pair<Symbol, bool>> Winner() const;
        [[nodiscard]] std::vector<std::shared_ptr<const Position>> GetOpenPositions() const;
        [[nodiscard]] Symbol LastPlaced() const;
        [[nodiscard]] Board GetBoard() const;
        void Print() const;

    private:
        std::shared_ptr<const Board> m_board_;
        std::shared_ptr<const Player> m_you_;
    };
}

#endif //GAME_STATE_H
