#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/tree_search_algorithm.h>
#include <mock_tree_factory.h>
#include <mock_node.h>

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockNode;
    using mocks::MockTreeFactory;
    using models::Node;
    using std::dynamic_pointer_cast;
    using std::shared_ptr;
    using std::make_shared;
    using std::vector;

    class MonteCarloModelsFixture : public ::testing::Test
    {
    };

    TEST_F(MonteCarloModelsFixture, test)
    {
        EXPECT_EQ(0, 0);
    }
}

