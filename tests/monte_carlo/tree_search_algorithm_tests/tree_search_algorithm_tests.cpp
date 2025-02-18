#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/tree_search_algorithm.h>
#include "mock_node.h"
#include "mock_action.h"
#include "mock_action_select_strategy.h"

namespace sophia::monte_carlo::tree_search_algorithm_tests {

    class MonteCarloFixture : public ::testing::Test
    {
    };

    TEST_F(MonteCarloFixture, tree_search_algorithm_test)
    {
        using models::Node;
        using std::shared_ptr;
        using std::make_shared;
        using std::vector;

        auto action_select_strategy = make_shared<MockActionSelectStrategy>();
        const auto s0 = make_shared<MockNode>("s0", action_select_strategy);
        auto s1 = make_shared<MockNode>("s1", action_select_strategy);
        auto s2 = make_shared<MockNode>("s2", action_select_strategy);
        auto s3 = make_shared<MockNode>("s3", action_select_strategy);
        auto s4 = make_shared<MockNode>("s4", action_select_strategy);
        auto s5 = make_shared<MockNode>("s5", action_select_strategy);
        auto s6 = make_shared<MockNode>("s6", action_select_strategy);

        s0->Setup({ s1, s2 });
        s1->Setup({ s3, s4 });
        s1->Setup(20);
        s2->Setup({ s5, s6 });
        s2->Setup(10);
        s3->Setup(0);
        s5->Setup(14);

        // the tree starts with two actions?
        s0->Expand();
        shared_ptr<Node> best_decision = tree_search_algorithm(s0, 4);

        EXPECT_EQ(best_decision->Name(), "s2");
    }
}

