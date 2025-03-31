#include <tic_tac_toe/factories/tic_tac_toe_factory.h>
#include <monte_carlo/tree_search_algorithm.h>
#include <iostream>
#include <memory>
#include <utility>

using sophia::examples::tic_tac_toe::factories::TicTacToeFactory;
using sophia::monte_carlo::tree_search_algorithm;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;

std::shared_ptr<Node> process_player_move(const std::shared_ptr<Node> &node);
bool is_valid(const std::string &input);

int main()
{
    std::cout << "Let's Play Tic Tac Toe!" << std::endl;

    const auto factory = std::make_shared<const TicTacToeFactory>();
    const auto root = factory->CreateNode("0");

    std::shared_ptr<Node> current = root;
    bool your_turn = false;
    while(!current->IsTerminalState())
    {
        if (not your_turn)
        {
            auto best_action = tree_search_algorithm(current, 50);
            current = best_action;
            current->Print();
            your_turn = !your_turn;
            continue;
        }

        std::shared_ptr<Node> next_node = nullptr;
        while (next_node == nullptr)
        {
            next_node = process_player_move(current);
            next_node->Print();
        }
        current = next_node;
        your_turn = !your_turn;
    }

    return 0;
}

std::shared_ptr<Node> process_player_move(const std::shared_ptr<Node> &node)
{
    node->Print();
    std::string move;
    std::cout << "Enter your move : ";
    std::getline(std::cin, move);

    std::shared_ptr<Action> action;
    if (is_valid(move) && ((action = node->SelectAction(move))))
    {
        action->Generate();
        return action->Target();
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
