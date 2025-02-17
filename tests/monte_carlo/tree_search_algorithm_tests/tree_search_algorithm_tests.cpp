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
        using ::testing::Return;
        using ::testing::_;

        shared_ptr<MockActionSelectStrategy> action_select_strategy = make_shared<MockActionSelectStrategy>();
        shared_ptr<MockNode> s0 = make_shared<MockNode>("s0", action_select_strategy);
        shared_ptr<MockNode> s1 = make_shared<MockNode>("s1", action_select_strategy);
        shared_ptr<MockNode> s2 = make_shared<MockNode>("s2", action_select_strategy);

        shared_ptr<MockNode> s3 = make_shared<MockNode>("s3", action_select_strategy);
        shared_ptr<MockNode> s4 = make_shared<MockNode>("s4", action_select_strategy);
        shared_ptr<MockNode> s5 = make_shared<MockNode>("s5", action_select_strategy);
        shared_ptr<MockNode> s6 = make_shared<MockNode>("s6", action_select_strategy);
        shared_ptr<MockNode> st = make_shared<MockNode>("terminal", action_select_strategy);

        s0->Mock({ s1, s2 });
        s1->Mock({ s3, s4 }, 20);
        s2->Mock({ s5, s6 }, 10);
        s3->Mock({  }, 0);
        s5->Mock({  }, 14);

        s0->Expand();

        shared_ptr<Node> best_decision = tree_search_algorithm(s0, 4);

        EXPECT_EQ(best_decision->Name(), "s2");
    }
}

