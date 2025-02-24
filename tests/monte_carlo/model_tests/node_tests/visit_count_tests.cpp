#include <gtest/gtest.h>
#include <mock_node.h>
#include "monte_carlo_models_fixture.h"

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockNode;

    TEST_F(MonteCarloModelsFixture, visit_count_default_value_test)
    {
        const auto n = MockNode("name 1", nullptr);

        const auto total_reward = n.VisitCount();

        EXPECT_EQ(total_reward, 0);
    }

    TEST_F(MonteCarloModelsFixture, node_visit_count_with_non_default_value_test)
    {
        auto n = MockNode("name 1", nullptr);

        n.SetVisitCount(3);

        const auto total_reward = n.VisitCount();

        EXPECT_EQ(total_reward, 3);
    }
}

