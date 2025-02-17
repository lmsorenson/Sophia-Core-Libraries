#include <monte_carlo/tree_search_algorithm.h>
#include <monte_carlo/models/node.h>
#include "monte_carlo/models/action.h"
#include <iostream>



using sophia::monte_carlo::tree_search_algorithm;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using std::shared_ptr;

shared_ptr<Node> sophia::monte_carlo::tree_search_algorithm(const shared_ptr<Node>& root, const int iterations)
{
    if (iterations < 0 || iterations > 1000)
    {
        std::cerr << "Invalid iterations" << std::endl;
        throw std::invalid_argument("Invalid iterations");
    }

    for(int i = 0; i < iterations; i++)
    {
        shared_ptr<Node> current = root;
        std::cout << std::endl << "Iteration=" << i+1 << std::endl;
        std::cout << "Phase 1: Selection" << std::endl;
        while (!current->IsLeafNode())
        {
            const auto action = current->SelectBestAction();
            current = action->Target();
            std::cout
            << "Selecting " << current->Name()
            << ": t=" << current->TotalReward()
            << ", n=" << current->VisitCount() << std::endl;
        }

        std::cout << "Phase 2: Has " << current->Name() << " been sampled?" << std::endl;
        if (current->HasBeenSampled())
        {
            std::cout << "Yes, expand it." << std::endl;
            current = current->Expand();
        }
        else
        {
            std::cout << "No, don't expand it."
            "" << std::endl;
        }

        std::cout << "Phase 3: Rollout" << std::endl;
        const double reward = current->Rollout();

        std::cout << "Phase 4: Backpropagation" << std::endl;
        current->Backpropagate(reward);
    }

    std::cout << std::endl << "Process Complete: Selecting Best Action" << std::endl;
    const auto action = root->SelectBestAction();
    auto selected_action = action->Target();
    std::cout << "Best action: " << selected_action->Name() << std::endl;
    return selected_action;
}
