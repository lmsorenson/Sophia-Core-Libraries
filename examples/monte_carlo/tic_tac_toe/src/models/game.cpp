#include <tic_tac_toe/models/game.h>
#include <tic_tac_toe/models/board.h>
#include <memory>

using sophia::examples::tic_tac_toe::models::Game;
using sophia::examples::tic_tac_toe::models::const_player_ptr;
using std::make_shared;
using std::shared_ptr;

Game::Game()
: board_(make_shared<Board>())
{
}

Game::~Game() = default;

bool Game::game_over() const
{
    return board_->Winner() != nullptr;
}

const_player_ptr Game::active_player() const
{
    if (game_states_.empty())
    {
        return x_;
    }

    const auto current_state = game_states_.back();

    switch (current_state->LastPlaced())
    {
        case Symbol::X: return o_;
        case Symbol::O: return x_;
        default: throw std::runtime_error("Last Placed symbol is not a valid symbol.");
    }
}

void Game::accept_move(const Position move)
{
    auto new_board = board_->WithMove(move);

    if (new_board != nullptr)
    {
        board_ = new_board;
    }
}

void Game::print() const
{
    board_->Print();
}
