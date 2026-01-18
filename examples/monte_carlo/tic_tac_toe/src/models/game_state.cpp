#include <tic_tac_toe/models/game_state.h>

#include <utility>

using sophia::monte_carlo::tic_tac_toe::models::GameState;
using sophia::monte_carlo::tic_tac_toe::models::Board;
using sophia::monte_carlo::tic_tac_toe::models::Player;
using sophia::monte_carlo::tic_tac_toe::enums::Symbol;
using sophia::monte_carlo::tic_tac_toe::const_game_state_ptr;
using sophia::monte_carlo::tic_tac_toe::const_board_ptr;
using sophia::monte_carlo::tic_tac_toe::const_position_ptr;
using sophia::monte_carlo::tic_tac_toe::const_player_ptr;

GameState::GameState(const_player_ptr you, const_board_ptr board)
    : m_you_(std::move(you))
    , m_board_(std::move(board))
{
}

GameState::GameState(const_player_ptr you, const_board_ptr board, Symbol last_placed)
    : m_you_(std::move(you))
    , m_board_(std::move(board))
{
}

const_game_state_ptr GameState::ApplyMove(const Position &position) const
{
    auto new_board = m_board_->WithMove(position);

    return std::make_shared<GameState>(m_you_, new_board, position.State());
}

const_player_ptr GameState::You() const
{
    return m_you_;
}

std::shared_ptr<std::pair<Symbol, bool>> GameState::Winner() const
{
    return m_board_->Winner();
}

std::vector<const_position_ptr> GameState::GetOpenPositions() const
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

int GameState::GetTurnNumber() const
{
    return m_board_->GetMarkCount();
}

void GameState::Print() const
{
    m_board_->Print();
}
