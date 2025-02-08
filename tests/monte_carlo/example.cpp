#include <gtest/gtest.h>
#include <monte_carlo/library.h>

class MonteCarloFixture : public ::testing::Test
{

};

TEST_F(MonteCarloFixture, eample_test)
{
    sophia::monte_carlo::hello();

    EXPECT_EQ(1, 1);
}