#include "monte_carlo_nodes_fixture.h"
#include <gtest/gtest.h>
#include <mock_node.h>
#include <mock_tree_factory.h>

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockNode;

    TEST_F(MonteCarloModelsFixture, node_backpropagate_test)
    {
        auto factory = std::make_shared<mocks::MockTreeFactory>();

        auto s1 = factory->CreateNode("S1");
        auto s2 = factory->CreateNode("S2");
        auto s1_ = std::static_pointer_cast<MockNode>(s1);
        auto a1 = factory->CreateAction(s1_, 1);
        s2->SetParent(a1);

        s1->Backpropagate(10);
        s2->Backpropagate(10);
        s2->Backpropagate(10);

        const auto actualVisitCountS1 = s1->VisitCount();
        const auto actualTotalRewardS1 = s1->TotalReward();
        const auto actualVisitCountS2 = s2->VisitCount();
        const auto actualTotalRewardS2 = s2->TotalReward();

        EXPECT_EQ(actualVisitCountS1, 3);
        EXPECT_EQ(actualTotalRewardS1, 30);
        EXPECT_EQ(actualVisitCountS2, 2);
        EXPECT_EQ(actualTotalRewardS2, 20);
    }
}

