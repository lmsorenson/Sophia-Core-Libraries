#include "monte_carlo_nodes_fixture.h"
#include <gtest/gtest.h>
#include <mock_node.h>

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockNode;

    TEST_F(MonteCarloModelsFixture, node_name_test)
    {
        const auto n = MockNode("name 1", nullptr);

        const auto name = n.Name();

        EXPECT_EQ(name, "name 1");
    }
}

