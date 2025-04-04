#include <tic_tac_toe/factories/tic_tac_toe_factory.h>
#include <tic_tac_toe/models/game_state.h>
#include <tic_tac_toe/models/human.h>
#include <tic_tac_toe/models/bot.h>
#include <tic_tac_toe/models/board.h>
#include <monte_carlo/tree_search_algorithm.h>
#include <iostream>
#include <memory>
#include <utility>

using sophia::examples::tic_tac_toe::factories::TicTacToeFactory;
using sophia::examples::tic_tac_toe::models::GameState;
using sophia::examples::tic_tac_toe::models::Board;
using sophia::examples::tic_tac_toe::models::Human;
using sophia::examples::tic_tac_toe::models::Bot;
using sophia::monte_carlo::tree_search_algorithm;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using std::make_shared;


int main()
{
    std::cout << "Let's Play Tic Tac Toe!" << std::endl;

    const auto factory = std::make_shared<const TicTacToeFactory>();
    const auto root = factory->CreateNode("0");

    auto x = make_shared<Human>(Symbol::X);
    auto o = make_shared<Bot>(Symbol::O);
    auto board = make_shared<Board>();
    auto game_state = make_shared<GameState>(o, x, board);

    std::shared_ptr<Node> current = root;
    while(!current->IsTerminalState())
    {
        const auto player = game_state->CurrentPlayer();
        auto node = factory->CreateNode("0", *game_state);
        const auto action = player->GenerateAction(node);
        const auto new_node = action->Target();
        new_node->Print();


    }

    return 0;
}
