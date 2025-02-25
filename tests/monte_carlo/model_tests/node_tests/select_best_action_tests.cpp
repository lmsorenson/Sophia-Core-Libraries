#include "monte_carlo_models_fixture.h"
#include <gtest/gtest.h>
#include <mock_node.h>
#include <mock_tree_factory.h>

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockTreeFactory;
    using mocks::MockNode;

    TEST_F(MonteCarloModelsFixture, node_select_best_action_no_scores_test)
    {
        const auto factory = std::make_shared<MockTreeFactory>();
        const auto s1 = factory->CreateNode("S1");
        const auto s2 = factory->CreateNode("S2");
        const auto s3 = factory->CreateNode("S3");

        std::dynamic_pointer_cast<MockNode>(s1)->Setup({ s2, s3 });
        s1->Expand();

        const auto best_action = s1->SelectBestAction();
        const auto best_node = best_action->Target();

        EXPECT_EQ(best_node->Name(), "S2");
    }

    TEST_F(MonteCarloModelsFixture, node_select_best_action_choose_node_with_no_scores_test)
    {
        const auto factory = std::make_shared<MockTreeFactory>();
        const auto s1 = factory->CreateNode("S1");
        const auto s2 = factory->CreateNode("S2");
        const auto s3 = factory->CreateNode("S3");

        std::dynamic_pointer_cast<MockNode>(s1)->Setup({ s2, s3 });
        s1->Expand();
        s2->Backpropagate(20);

        const auto best_action = s1->SelectBestAction();
        const auto best_node = best_action->Target();

        EXPECT_EQ(best_node->Name(), "S3");
    }

    TEST_F(MonteCarloModelsFixture, node_select_best_action_choose_node_with_best_scores_test)
    {
        const auto factory = std::make_shared<MockTreeFactory>();
        const auto s1 = factory->CreateNode("S1");
        const auto s2 = factory->CreateNode("S2");
        const auto s3 = factory->CreateNode("S3");

        std::dynamic_pointer_cast<MockNode>(s1)->Setup({ s2, s3 });
        s1->Expand();
        s2->Backpropagate(20);
        s3->Backpropagate(30);

        const auto best_action = s1->SelectBestAction();
        const auto best_node = best_action->Target();

        EXPECT_EQ(best_node->Name(), "S3");
    }
}

