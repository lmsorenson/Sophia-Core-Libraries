#include <monte_carlo/tree_search_algorithm.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>
#include <iomanip> // For std::setw, std::left

using sophia::monte_carlo::MonteCarloTreeSearch;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using sophia::logging::logger_ptr;
using std::shared_ptr;

std::shared_ptr<Action> MonteCarloTreeSearch::run(
    const std::shared_ptr<models::Node> &root,
    int iterations,
    const logger_ptr& logger)
{
    if (!root)
    {
        if (logger) logger->error("MCTS::run called with a null root node.");
        throw std::invalid_argument("Root node cannot be null.");
    }
    
    if (iterations < 0 || iterations > 20000)
    {
        if (logger) logger->error("Invalid number of iterations: {}", iterations);
        throw std::invalid_argument("Invalid number of iterations");
    }

    for(int i = 0; i < iterations; i++)
    {
        if (logger) logger->info("\n--- Iteration {} ---", i + 1);

        shared_ptr<Node> current = root;

        // --- 1. Selection ---
        if (logger) logger->info("Phase 1: Selection");
        while (!current->IsLeafNode())
        {
            const auto action = current->SelectBestAction();
            if (!action || !action->Target())
            {
                if (logger) logger->error("Selection phase returned a null action or target node from non-leaf node '{}'.", current->Name());
                // Break the loop to prevent crash, will proceed to rollout from current node
                break;
            }
            current = action->Target();
        }
        if (logger) logger->debug("  Selection finished at node: {}", current->Name());

        // --- 2. Expansion ---
        if (logger) logger->info("Phase 2: Expansion");
        if (current->HasBeenSampled() && !current->IsTerminalState())
        {
            if (logger) logger->debug("  Node '{}' has been sampled. Expanding...", current->Name());
            auto first_expansion_node = current->Expand();
            if (first_expansion_node)
            {
                current = first_expansion_node;
            }
            else
            {
                 if (logger) logger->debug("  Node '{}' did not expand (might be terminal or have no actions).", current->Name());
            }
        }
        else
        {
            if (logger)
            {
                if (current->IsTerminalState())
                    logger->debug("  Node '{}' is a terminal state. Skipping expansion.", current->Name());
                else
                    logger->debug("  Node '{}' has not been sampled. Skipping expansion.", current->Name());
            }
        }

        // --- 3. Rollout (Simulation) ---
        if (logger) logger->info("Phase 3: Rollout (Simulation)");
        const double reward = current->Rollout();
        if (logger) logger->debug("  Rollout from '{}' finished with reward: {:.4f}", current->Name(), reward);

        // --- 4. Backpropagation ---
        if (logger) logger->info("Phase 4: Backpropagation");
        current->Backpropagate(reward);
    }

    if (logger)
    {
        logger->info("\n--- MCTS Complete: Final Action Summary ---");
        logger->info("{:<20} | {:<15} | {:<12}", "Action (-> Node)", "Avg. Reward", "Visit Count");
        logger->info("----------------------------------------------------------");

        auto final_actions = root->GetAvailableActions();
        for (const auto& action : final_actions)
        {
            auto target = action->Target();
            if (target && target->VisitCount() > 0)
            {
                double avg_reward = target->TotalReward() / target->VisitCount();
                std::string action_name = "'" + action->Name() + "' -> '" + target->Name() + "'";
                logger->info("{:<20} | {:<15.4f} | {:<12}", action_name, avg_reward, target->VisitCount());
            }
            else
            {
                logger->info("{:<20} | {:<15} | {:<12}", action->Name(), "N/A", 0);
            }
        }
        logger->info("----------------------------------------------------------");
    }

    const auto best_action = root->SelectAction();
    if (logger && best_action && best_action->Target())
    {
        logger->info("=> Best Action Selected: '{}' (leading to node '{}')", best_action->Name(), best_action->Target()->Name());
    } else if (logger)
    {
        logger->warn("=> No best action could be selected.");
    }

    return best_action;
}

