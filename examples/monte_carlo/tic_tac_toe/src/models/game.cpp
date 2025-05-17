#include <tic_tac_toe/models/game.h>
#include <tic_tac_toe/models/board.h>
#include <memory>
#include <tic_tac_toe/models/game_state.h>

using sophia::examples::tic_tac_toe::models::Game;
using sophia::examples::tic_tac_toe::models::const_player_ptr;
using std::make_shared;
using std::shared_ptr;

Game::Game()
{
    game_states_.push_back(make_shared<Board>());
};
Game::~Game() = default;

bool Game::game_over() const
{
    if (game_states_.empty()) return false;

    const auto current_state = game_states_.back();

    return current_state->Winner() != nullptr;
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
        default: case Symbol::O: return x_;
    }
}

void Game::accept_move(const Position move)
{
    if (game_states_.empty()) return;

    const auto current_state = game_states_.back();

    const auto new_state = current_state->WithMove(move);

    if (new_state != nullptr)
    {
        game_states_.push_back(new_state);
        notify();
    }
}

void Game::print() const
{
    if (game_states_.empty()) return;

    const auto current_state = game_states_.back();

    current_state->Print();
}
