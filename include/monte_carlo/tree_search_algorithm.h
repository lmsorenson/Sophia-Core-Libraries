#ifndef TREE_SEARCH_ALGORITHM_H
#define TREE_SEARCH_ALGORITHM_H

#include <monte_carlo/models/node.h>

namespace sophia::monte_carlo
{
    std::shared_ptr<models::Action> tree_search_algorithm(const std::shared_ptr<models::Node>& root, int iterations);
}

#endif //TREE_SEARCH_ALGORITHM_H
