#include <tic_tac_toe/models/human.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>
#include <tic_tac_toe/models/board.h>
#include <iostream>

using sophia::examples::tic_tac_toe::models::Human;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::models::Node;
using std::shared_ptr;

std::shared_ptr<Action> process_player_move(const std::shared_ptr<Node> &node);
bool is_valid(const std::string &input);

Human::Human(const Symbol symbol)
    : Player(symbol)
{
    std::cout << "Creating human" << std::endl;
}

shared_ptr<Action> Human::GenerateAction(const shared_ptr<Node> &node) const
{
    std::shared_ptr<Action> next_action = nullptr;

    while (next_action == nullptr)
    {
        next_action = process_player_move(node);
    }

    return next_action;
}

std::shared_ptr<Action> process_player_move(const std::shared_ptr<Node> &node)
{
    node->Print();
    std::string move;
    std::cout << "Enter your move : ";
    std::getline(std::cin, move);

    std::shared_ptr<Action> action;
    if (is_valid(move) && ((action = node->SelectAction(move))))
    {
        action->Generate();
        return action;
    }
    else
    {
        std::cout << "Invalid input format! Expected letter + digit (e.g., A1).\n";
        return nullptr;
    }
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
