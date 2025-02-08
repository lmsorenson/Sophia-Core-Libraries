#include <gtest/gtest.h>

class ExampleFixture : public ::testing::Test
{

};

TEST_F(ExampleFixture, eample_test)
{
    EXPECT_EQ(1, 1);
}