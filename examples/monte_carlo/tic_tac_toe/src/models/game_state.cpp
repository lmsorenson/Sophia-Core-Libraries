#include <tic_tac_toe/models/game_state.h>

#include <utility>

using sophia::examples::tic_tac_toe::models::GameState;
using sophia::examples::tic_tac_toe::models::Board;
using sophia::examples::tic_tac_toe::models::Player;

GameState::GameState(const_player_ptr you, const_player_ptr opponent, std::shared_ptr<const Board> board)
    : m_you_(std::move(you))
    , m_opponent_(std::move(opponent))
    , m_board_(std::move(board))
{
}

GameState::GameState(const_player_ptr you, const_player_ptr opponent, std::shared_ptr<const Board> board, Symbol last_placed)
    : m_you_(std::move(you))
    , m_opponent_(std::move(opponent))
    , m_board_(std::move(board))
{
}

std::shared_ptr<const GameState> GameState::ApplyMove(const Position &position) const
{
    auto new_board = m_board_->WithMove(position);

    return std::make_shared<GameState>(m_you_, m_opponent_, new_board, position.State());
}

std::shared_ptr<const Player> GameState::CurrentPlayer() const
{
    auto last_placed = m_board_->LastPlaced();
    if (last_placed == Symbol::None && m_you_->symbol() == Symbol::X)
    {
        return m_you_;
    }

    if (last_placed == Symbol::None && m_opponent_->symbol() == Symbol::X)
    {
        return m_opponent_;
    }

    if (m_you_->symbol() != last_placed)
    {
        return m_you_;
    }

    return m_opponent_;
}

std::shared_ptr<const Player> GameState::You() const
{
    return m_you_;
}

std::shared_ptr<std::pair<Symbol, bool>> GameState::Winner() const
{
    return m_board_->Winner();
}

std::vector<std::shared_ptr<const sophia::examples::tic_tac_toe::models::Position>> GameState::GetOpenPositions() const
{
    return m_board_->GetOpenPositions();
}

Symbol GameState::LastPlaced() const
{
    return m_board_->LastPlaced();
}

Board GameState::GetBoard() const
{
    return *m_board_;
}

void GameState::Print() const
{
    m_board_->Print();
}
