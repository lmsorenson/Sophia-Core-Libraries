#include <gtest/gtest.h>
#include <mock_node.h>
#include "monte_carlo_models_fixture.h"

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockNode;

    TEST_F(MonteCarloModelsFixture, visit_count_0_test)
    {
        const auto n = MockNode("name 1", nullptr);

        const auto total_reward = n.VisitCount();

        EXPECT_EQ(total_reward, 0);
    }

    TEST_F(MonteCarloModelsFixture, visit_count_backpropagated_test)
    {
        auto n = MockNode("name 1", nullptr);

        n.Backpropagate(50);
        n.Backpropagate(20);
        n.Backpropagate(13);

        const auto total_reward = n.VisitCount();

        EXPECT_EQ(total_reward, 3);
    }
}

