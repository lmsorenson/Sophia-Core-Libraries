#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/tree_search_algorithm.h>
#include "mock_node.h"
#include "mock_tree_factory.h"

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

        const auto factory = make_shared<MockTreeFactory>();
        const auto s0 = factory->CreateNode("s0");
        auto s1 = factory->CreateNode("s1");
        auto s2 = factory->CreateNode("s2");
        auto s3 = factory->CreateNode("s3");
        auto s4 = factory->CreateNode("s4");
        auto s5 = factory->CreateNode("s5");
        auto s6 = factory->CreateNode("s6");

        std::dynamic_pointer_cast<MockNode>(s0)->Setup({ s1, s2 });
        std::dynamic_pointer_cast<MockNode>(s1)->Setup({ s3, s4 });
        std::dynamic_pointer_cast<MockNode>(s1)->Setup(20);
        std::dynamic_pointer_cast<MockNode>(s2)->Setup({ s5, s6 });
        std::dynamic_pointer_cast<MockNode>(s2)->Setup(10);
        std::dynamic_pointer_cast<MockNode>(s3)->Setup(0);
        std::dynamic_pointer_cast<MockNode>(s5)->Setup(14);

        // the tree starts with two actions?
        s0->Expand();
        const shared_ptr<Node> best_decision = tree_search_algorithm(s0, 4);

        EXPECT_EQ(best_decision->Name(), "s2");
    }
}

