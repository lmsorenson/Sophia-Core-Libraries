#include <tic_tac_toe/models/Bot.h>
#include <tic_tac_toe/models/Board.h>
#include <monte_carlo/tree_search_algorithm.h>
#include <iostream>

using sophia::examples::tic_tac_toe::models::Bot;
using sophia::monte_carlo::tree_search_algorithm;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using std::shared_ptr;

Bot::Bot(const Symbol symbol)
    : Player(symbol)
{
    std::cout << "Creating bot" << std::endl;
}

shared_ptr<Action> Bot::GenerateAction(const shared_ptr<Node> &node) const
{
    return tree_search_algorithm(node, 50);
}