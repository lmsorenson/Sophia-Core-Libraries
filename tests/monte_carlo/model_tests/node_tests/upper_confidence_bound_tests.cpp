#include "monte_carlo_models_fixture.h"
#include <gtest/gtest.h>
#include <mock_node.h>
#include <mock_tree_factory.h>

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockTreeFactory;
    using mocks::MockNode;

    TEST_F(MonteCarloModelsFixture, node_upper_confidence_bound_infinity_test)
    {
        const auto factory = std::make_shared<MockTreeFactory>();
        const auto s1 = factory->CreateNode("S1");

        std::dynamic_pointer_cast<MockNode>(s1)->SetTotalReward(0);
        std::dynamic_pointer_cast<MockNode>(s1)->SetVisitCount(0);

        const auto ucb = s1->UpperConfidenceBound();

        EXPECT_EQ(ucb, std::numeric_limits<double>::infinity());
    }

    TEST_F(MonteCarloModelsFixture, node_upper_confidence_bound_value_test)
    {
        const auto factory = std::make_shared<MockTreeFactory>();
        const auto s1 = factory->CreateNode("S1");
        const auto s2 = factory->CreateNode("S2");
        const auto s3 = factory->CreateNode("S3");

        std::dynamic_pointer_cast<MockNode>(s1)->Setup({ s2, s3 });
        s1->Expand();
        std::dynamic_pointer_cast<MockNode>(s1)->SetTotalReward(20);
        std::dynamic_pointer_cast<MockNode>(s1)->SetVisitCount(1);
        std::dynamic_pointer_cast<MockNode>(s2)->SetTotalReward(20);
        std::dynamic_pointer_cast<MockNode>(s2)->SetVisitCount(1);

        const auto ucb = s2->UpperConfidenceBound();

        EXPECT_EQ(ucb, 20);
    }
}

