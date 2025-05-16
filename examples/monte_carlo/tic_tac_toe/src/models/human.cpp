#include <tic_tac_toe/models/human.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>
#include <tic_tac_toe/models/board.h>
#include <iostream>

using sophia::examples::tic_tac_toe::models::Human;
using sophia::examples::tic_tac_toe::models::Board;
using sophia::examples::tic_tac_toe::models::Position;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::models::Node;
using std::shared_ptr;
using std::pair;
using std::string;

std::shared_ptr<const Position> process_player_move(Symbol symbol);
pair<int,int> parse_move(const std::string &input);
bool is_valid(const std::string &input);

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

std::shared_ptr<const Position> process_player_move(Symbol symbol)
{
    std::string move;
    std::cout << "Enter your move : ";
    std::getline(std::cin, move);

    if (is_valid(move))
    {
        auto coordinates = parse_move(move);
        const auto position = std::make_shared<Position>(coordinates, symbol);
        return position;
    }
    else
    {
        std::cout << "Invalid input format! Expected letter + digit (e.g., A1).\n";
        return nullptr;
    }
}

pair<int, int> parse_move(const std::string &input)
{
    if (input.length() != 2)
    {
        throw std::invalid_argument("Invalid input format!");
    }

    int r = std::toupper(input[0]) - 'A' + 1;
    int c = input[1] - '0';

    return { r - 1, c - 1 };
}

bool is_valid(const std::string &input)
{
    bool is_valid = input.length() == 2;
    is_valid = is_valid && std::isalpha(input[0]);
    is_valid = is_valid && std::isdigit(input[1]);
    if (!is_valid)
    {
        return is_valid;
    }

    const char row_letter = input[0];
    int r = std::toupper(row_letter) - 'A' + 1;
    is_valid = r >= 1 && r <= 3;
    if (!is_valid)
    {
        return is_valid;
    }

    int c = input[1] - '0';
    is_valid = c >= 1 && c <= 3;
    if (!is_valid)
    {
        return is_valid;
    }

    return true;
}
