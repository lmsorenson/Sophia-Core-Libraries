#include <monte_carlo/tree_search_algorithm.h>
#include <monte_carlo/models/node.h>
#include "monte_carlo/models/action.h"
#include <iostream>

using sophia::monte_carlo::MonteCarloTreeSearch;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using std::shared_ptr;

std::shared_ptr<Action> MonteCarloTreeSearch::run(const std::shared_ptr<models::Node> &root, int iterations, bool verbose)
{
    if (iterations < 0 || iterations > 20000)
    {
        std::cerr << "Invalid iterations" << std::endl;
        throw std::invalid_argument("Invalid iterations");
    }

    for(int i = 0; i < iterations; i++)
    {
        shared_ptr<Node> current = root;
        if (verbose)
        {
            std::cout << std::endl << "Iteration=" << i+1 << std::endl;
            std::cout << "Phase 1: Selection" << std::endl;
        }

        while (!current->IsLeafNode())
        {
            const auto action = current->SelectBestAction();
            current = action->Target();
            if (verbose)
            {
                std::cout
                << "Selecting " << current->Name()
                << ": t=" << current->TotalReward()
                << ", n=" << current->VisitCount() << std::endl;
            }
        }

        if (verbose)
        {
            std::cout << "Phase 2: Has " << current->Name() << " been sampled?" << std::endl;
        }

        if (current->HasBeenSampled())
        {
            if (verbose)
            {
                std::cout << "Yes, expand it." << std::endl;
            }
            auto first_expansion_node= current->Expand();
            if (first_expansion_node == nullptr)
                continue;

            current = first_expansion_node;
        }
        else
        {
            if (verbose)
            {
                std::cout << "No, don't expand it." << std::endl;
            }
        }

        if (verbose)
        {
            std::cout << "Phase 3: Rollout" << std::endl;
        }
        const double reward = current->Rollout();
        if (verbose)
        {
            std::cout << "Reward " << reward << std::endl;
        }

        if (verbose)
        {
            std::cout << "Phase 4: Backpropagation" << std::endl;
        }
        current->Backpropagate(reward);
    }

    if (verbose)
    {
        std::cout << std::endl << "Process Complete: Selecting Best Action" << std::endl;
    }
    const auto action = root->SelectAction();
    if (verbose)
    {
        const auto selected_action = action->Name();
        std::cout << "Best action: " << selected_action << std::endl;
    }
    return action;
}
