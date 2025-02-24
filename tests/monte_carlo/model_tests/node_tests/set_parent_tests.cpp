#include "monte_carlo_models_fixture.h"
#include <gtest/gtest.h>
#include <mock_node.h>
#include <monte_carlo/models/action.h>

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockNode;
    using models::Action;

    TEST_F(MonteCarloModelsFixture, set_parent_test)
    {
        auto s1 = std::make_shared<MockNode>("node 1", nullptr);
        auto s2 = std::make_shared<MockNode>("node 2", nullptr);

        const auto a1 = std::make_shared<Action>(s1, s2);
        s2->SetParent(a1);

        s2->Backpropagate(10);

        const auto ucb = s2->UpperConfidenceBound();

        EXPECT_EQ(ucb, 10);
    }
}

