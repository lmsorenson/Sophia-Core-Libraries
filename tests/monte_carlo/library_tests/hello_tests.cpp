#include <gtest/gtest.h>
#include <monte_carlo/library.h>

namespace sophia::monte_carlo::library_tests {

    // class MonteCarloFixture : public ::testing::Test
    // {
    // };

    TEST(MonteCarloFixture, hello_world_test)
    {
        hello();

        EXPECT_EQ(1, 1);
    }

    TEST(MonteCarloFixture, hello_world_test_2)
    {
        hello();

        EXPECT_EQ(1, 1);
    }

}

