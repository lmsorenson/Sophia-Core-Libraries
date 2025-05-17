#include <tic_tac_toe/factories/tic_tac_toe_factory.h>
#include <tic_tac_toe/models/human.h>
#include <tic_tac_toe/models/bot.h>
#include <tic_tac_toe/models/game.h>
#include <iostream>
#include <memory>
#include <utility>

using sophia::examples::tic_tac_toe::factories::TicTacToeFactory;
using sophia::examples::tic_tac_toe::models::Game;
using sophia::examples::tic_tac_toe::models::Human;
using sophia::examples::tic_tac_toe::models::Bot;
using std::make_shared;
using std::shared_ptr;


int main()
{
    std::cout << "Let's Play Tic Tac Toe!" << std::endl;

    const shared_ptr<Game> game = make_shared<Game>();
    game->print();

    game->Assign<Human>(Symbol::X);
    game->Assign<Bot>(Symbol::O);

    while(game->game_over() == false)
    {
        const auto current_player = game->active_player();

        const auto position = current_player->NextMove();

        if (position == nullptr)
            break;

        game->accept_move(*position);

        game->print();
    }

    return 0;
}
