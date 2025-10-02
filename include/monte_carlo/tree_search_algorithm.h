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
         * @brief Runs the Monte Carlo Search algorithm.
         *
         * @callgraph
         * @callergraph
         *
         * @param root
         * @param iterations
         * @return
         */
        static std::shared_ptr<models::Action> run(const std::shared_ptr<models::Node>& root, int iterations);
    };

}

#endif //TREE_SEARCH_ALGORITHM_H
