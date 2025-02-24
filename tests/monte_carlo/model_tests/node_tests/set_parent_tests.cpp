#include "monte_carlo_models_fixture.h"
#include <gtest/gtest.h>
#include <mock_node.h>
#include <monte_carlo/models/action.h>

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockNode;
    using models::Action;

    TEST_F(MonteCarloModelsFixture, node_set_parent_test)
    {
        auto s1 = std::make_shared<MockNode>("node 1", nullptr);
        auto s2 = std::make_shared<MockNode>("node 2", nullptr);
        const auto a1 = std::make_shared<Action>(s1, s2);

        // before the parent is set,
        // the parent should null.
        auto actualParent = s2->GetParent();
        EXPECT_EQ(actualParent, nullptr);

        // Execute
        s2->SetParent(a1);

        // after the parent is set,
        // the parent should not be null;
        actualParent = s2->GetParent();
        EXPECT_NE(actualParent, nullptr);
    }
}

