#include "monte_carlo_models_fixture.h"
#include <gtest/gtest.h>
#include <mock_node.h>
#include <mock_tree_factory.h>

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockTreeFactory;
    using mocks::MockNode;

    TEST_F(MonteCarloModelsFixture, node_rollout_test)
    {
        auto factory = std::make_shared<MockTreeFactory>();
        auto s1 = factory->CreateNode("S1");

        const auto name = s1->Rollout();

        EXPECT_EQ(name, -1);
    }

    TEST_F(MonteCarloModelsFixture, node_rollout_2_test)
    {
        auto factory = std::make_shared<MockTreeFactory>();
        auto s1 = factory->CreateNode("S1");
        auto s2 = factory->CreateNode("S2");
        auto s3 = factory->CreateNode("S3");

        std::dynamic_pointer_cast<MockNode>(s1)->Setup({ s2, s3 });
        std::dynamic_pointer_cast<MockNode>(s2)->Setup(20);
        s1->Expand();

        const auto name = s1->Rollout();

        EXPECT_EQ(name, 20);
    }
}

