#include "monte_carlo_nodes_fixture.h"
#include <gtest/gtest.h>
#include <mock_node.h>
#include <mock_tree_factory.h>
#include <monte_carlo/models/action.h>

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockNode;
    using models::Action;
    using std::dynamic_pointer_cast;

    TEST_F(MonteCarloModelsFixture, node_set_parent_test)
    {
        const auto factory = std::make_shared<mocks::MockTreeFactory>();

        auto s1 = factory->CreateNode("node 1");
        auto s2 = factory->CreateNode("node 2");
        const auto a1 = factory->CreateAction(s1);

        // before the parent is set,
        // the parent should null.
        auto actualParent = dynamic_pointer_cast<MockNode>(s2)->GetParent();
        EXPECT_EQ(actualParent, nullptr);

        // Execute
        s2->SetParent(a1);

        // after the parent is set,
        // the parent should not be null;
        actualParent = dynamic_pointer_cast<MockNode>(s2)->GetParent();
        EXPECT_NE(actualParent, nullptr);
    }
}

