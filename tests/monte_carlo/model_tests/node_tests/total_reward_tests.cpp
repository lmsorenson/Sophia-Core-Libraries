#include <gtest/gtest.h>
#include <mock_node.h>
#include "monte_carlo_models_fixture.h"

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockNode;

    TEST_F(MonteCarloModelsFixture, node_total_reward_default_value_test)
    {
        const auto n = MockNode("name 1", nullptr);

        const auto total_reward = n.TotalReward();

        EXPECT_EQ(total_reward, 0);
    }

    TEST_F(MonteCarloModelsFixture, node_total_reward_with_non_default_value_test)
    {
        auto n = MockNode("name 1", nullptr);

        n.SetTotalReward(30);

        const auto total_reward = n.TotalReward();

        EXPECT_EQ(total_reward, 30);
    }
}

