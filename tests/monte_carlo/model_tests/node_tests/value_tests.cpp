#include <gtest/gtest.h>
#include <mock_node.h>
#include "monte_carlo_models_fixture.h"

namespace sophia::monte_carlo::model_tests
{
    using mocks::MockNode;

    TEST_F(MonteCarloModelsFixture, value_test)
    {
        const auto n = MockNode("name 1", nullptr);

        const auto name = n.Value();

        EXPECT_EQ(name, 0);
    }
}

