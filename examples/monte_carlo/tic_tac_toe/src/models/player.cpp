#include <tic_tac_toe/models/player.h>
#include <tic_tac_toe/models/board.h>
#include <iostream>

using sophia::monte_carlo::tic_tac_toe::models::Player;
using sophia::monte_carlo::tic_tac_toe::enums::Symbol;

Player::Player(const Symbol symbol)
: m_player_symbol_(symbol)
{
}

Symbol Player::symbol() const
{
    return m_player_symbol_;
}

double Player::Value(const Board &board) const
{
    if (const auto winner = board.Winner())
    {
        if (winner->first == m_player_symbol_)
        {
            std::cout << "Player " << TileStateToString(m_player_symbol_) << " wins :)" << std::endl;
            return 1.0;
        }

        std::cout << "Player " << TileStateToString(m_player_symbol_) << " loses :(" << std::endl;
        return -1.0;
    }

    std::cout << "It's a draw :/" << std::endl;
    return 0.0;
}
