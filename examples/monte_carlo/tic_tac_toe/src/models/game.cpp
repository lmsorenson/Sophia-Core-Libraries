#include <tic_tac_toe/models/game.h>
#include <tic_tac_toe/models/board.h>
#include <memory>
#include <tic_tac_toe/models/game_state.h>
#include <logging/ilogger.h> // Added include for logger_ptr

using sophia::monte_carlo::tic_tac_toe::models::Game;
using ::tic_tac_toe::const_player_ptr;
using sophia::monte_carlo::tic_tac_toe::enums::Symbol;
using std::make_shared;
using std::shared_ptr;

Game::Game(const logger_ptr& logger)
: m_logger_(logger)
{
    game_states_.push_back(make_shared<Board>(m_logger_)); // Pass logger to Board constructor
    if (m_logger_) m_logger_->info("Game initialized.");
};
Game::~Game() = default;

bool Game::game_over() const
{
    if (game_states_.empty()) return false;

    const auto current_state = game_states_.back();

    auto winner_decided = current_state->Winner() != nullptr;
    auto open_positions = current_state->GetOpenPositions().size();

    return winner_decided || open_positions <= 0;
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
        case enums::Symbol::X: return o_;
        default: case enums::Symbol::O: return x_;
    }
}

void Game::accept_move(const Position move)
{
    if (game_states_.empty()) return;

    const auto current_state = game_states_.back();

    const auto new_state = current_state->WithMove(move);

    if (new_state != nullptr)
    {
        const auto name = move.Name();
        game_states_.push_back(new_state);
        notify(name);
    }
}

void Game::print() const
{
    if (game_states_.empty()) return;

    const auto current_state = game_states_.back();

    current_state->Print();
}
