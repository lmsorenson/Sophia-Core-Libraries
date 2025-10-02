#include <tic_tac_toe/models/human.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>
#include <tic_tac_toe/models/board.h>
#include <iostream>

using sophia::examples::tic_tac_toe::models::Human;
using sophia::examples::tic_tac_toe::models::Board;
using sophia::examples::tic_tac_toe::models::Position;
using sophia::examples::tic_tac_toe::enums::Symbol;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::models::Node;
using std::shared_ptr;
using std::pair;
using std::string;

std::shared_ptr<const Position> process_player_move(Symbol symbol);

Human::Human(const Symbol symbol)
    : Player(symbol)
{
    std::cout << "Creating human" << std::endl;
}

std::shared_ptr<const Position> Human::NextMove() const
{
    std::shared_ptr<const Position> position = nullptr;

    while (position == nullptr)
    {
        position = process_player_move(m_player_symbol_);
    }

    return position;
}

void Human::Update(const std::string message)
{
    std::cout << "human received Message: " << message << std::endl;
}

std::shared_ptr<const Position> process_player_move(Symbol symbol)
{
    std::string move;
    std::cout << "Enter your move : ";
    std::getline(std::cin, move);

    if (Position::is_valid(move))
    {
        auto coordinates = Position::parse_move(move);
        const auto position = std::make_shared<Position>(coordinates, symbol);
        return position;
    }
    else
    {
        std::cout << "Invalid input format! Expected letter + digit (e.g., A1).\n";
        return nullptr;
    }
}


