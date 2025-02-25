#include "monte_carlo_action_fixture.h"
#include <gtest/gtest.h>
#include <mock_node.h>
#include <mock_tree_factory.h>

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockTreeFactory;
    using mocks::MockNode;

    TEST_F(MonteCarloActionFixture, action_target_test)
    {
        const auto factory = std::make_shared<MockTreeFactory>();
        const auto s1 = factory->CreateNode("S1");
        const auto a1 = factory->CreateAction(nullptr, s1);

        const auto actual_target = a1->Target();

        EXPECT_NE(actual_target, nullptr);
    }

    TEST_F(MonteCarloActionFixture, action_target_null_test)
    {
        const auto factory = std::make_shared<MockTreeFactory>();
        const auto a1 = factory->CreateAction(nullptr, nullptr);

        const auto actual_target = a1->Target();

        EXPECT_EQ(actual_target, nullptr);
    }
}

