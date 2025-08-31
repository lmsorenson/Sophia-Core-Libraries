#include <tic_tac_toe/models/bot.h>
#include <tic_tac_toe/models/board.h>
#include <monte_carlo/tree_search_algorithm.h>
#include <iostream>
#include <tic_tac_toe/factories/tic_tac_toe_factory.h>

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
    if (node_ == nullptr)
    {
        return nullptr;
    }

    const shared_ptr<Action> best_action = tree_search_algorithm(node_, iterations_);

    const auto t = best_action->Target();

    const std::string move = t->Name();
    std::cout << "Bot move " << move << std::endl;
    if (Position::is_valid(t->Name()))
    {
        auto coords = Position::parse_move(t->Name());
        std::cout << "parsed " << "row " << coords.first << ", column " << coords.second << std::endl;
        std::cout << "mark " <<  TileStateToString(m_player_symbol_) << std::endl;

        return std::make_shared<Position>(coords, m_player_symbol_);
    }

    return nullptr;
}

void Bot::Update(const std::string message)
{
    std::cout << "Bot received message " << message << std::endl;

    // If the node is empty create a new one.
    if (node_ == nullptr)
    {
        const auto factory = std::make_shared<factories::TicTacToeFactory>(shared_from_this());
        node_ = factory->CreateNode("root");
    }

    // Select the message that is
    const auto action = node_->SelectAction(message);
    node_ = action->Target();

    std::cout << "Child node " << node_->Name() << " selected." << std::endl;
}
