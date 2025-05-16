#include <tic_tac_toe/models/bot.h>
#include <tic_tac_toe/models/board.h>
#include <monte_carlo/tree_search_algorithm.h>
#include <iostream>

using sophia::examples::tic_tac_toe::models::Bot;
using sophia::examples::tic_tac_toe::models::Position;
using sophia::monte_carlo::tree_search_algorithm;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using std::shared_ptr;

Bot::Bot(const Symbol symbol)
    : Player(symbol)
{
    std::cout << "Creating bot" << std::endl;
}

std::shared_ptr<const Position> Bot::NextMove() const
{
    shared_ptr<Action> best_action = tree_search_algorithm(node_, 100);

    return nullptr;
}