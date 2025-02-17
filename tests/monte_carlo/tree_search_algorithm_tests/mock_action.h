#ifndef MOCK_ACTION_H
#define MOCK_ACTION_H
#include <gmock/gmock.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>

#include <utility>

namespace sophia::monte_carlo::tree_search_algorithm_tests
{
    using models::Node;
    using models::Action;

    class MockAction : public Action
    {
    public:
        MockAction(std::shared_ptr<Node> source, std::shared_ptr<Node> target)
        : Action(std::move(source), std::move(target))
        {
        }
    };
}

#endif //MOCK_ACTION_H
