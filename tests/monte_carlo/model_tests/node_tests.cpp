#include <gtest/gtest.h>
#include <mock_node.h>

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockNode;

    class MonteCarloModelsFixture : public ::testing::Test
    {
    };

    TEST_F(MonteCarloModelsFixture, name_test)
    {
        const auto n = MockNode("name 1", nullptr);

        const auto name = n.Name();

        EXPECT_EQ(name, "name 1");
    }
}

