#ifndef TREE_SEARCH_ALGORITHM_H
#define TREE_SEARCH_ALGORITHM_H

#include <monte_carlo/models/node.h>

namespace sophia::monte_carlo
{
    /**
     * @class MonteCarloTreeSearch
     */
    class MonteCarloTreeSearch
    {
    public:
                /**
                 * @brief Executes the Monte Carlo Tree Search (MCTS) algorithm to find the best action from a given root state.
                 *
                 * MCTS is a general-purpose search algorithm for decision-making processes. It operates in four main phases,
                 * which are repeated for a specified number of iterations:
                 * 1.  **Selection:** Starting from the `root` node, recursively select child nodes with the highest
                 *     Upper Confidence Bound (UCB1) until a leaf node (a node with unexpanded potential) is reached.
                 * 2.  **Expansion:** If the selected leaf node is not a terminal state, create one or more child nodes
                 *     representing subsequent states. Select one of these new nodes.
                 * 3.  **Simulation (Rollout):** From the newly created node, perform a simulation (e.g., a random walk)
                 *     until a terminal state is reached. The outcome of this simulation is a reward.
                 * 4.  **Backpropagation:** Propagate the reward from the simulation back up the tree, updating the
                 *     visit counts and total rewards of all nodes and actions along the path to the root.
                 *
                 * After all iterations are complete, the algorithm selects the action from the root node
                 * that is considered the most promising, typically based on the highest average reward or visit count.
                 *
                      * @param root A shared pointer to the initial `Node` representing the starting state of the problem.
                      * @param iterations The total number of MCTS iterations to perform. Each iteration involves
                      *                   one cycle of selection, expansion, simulation, and backpropagation.
                      * @param verbose If true, print detailed logs of each iteration's phases to standard output. Defaults to false.
                      * @return A shared pointer to the `Action` determined to be the best decision from the root state.
                      */
                     static std::shared_ptr<models::Action> run(const std::shared_ptr<models::Node>& root, int iterations, bool verbose = false);    };

}

#endif //TREE_SEARCH_ALGORITHM_H
