#include <gtest/gtest.h>
#include <factories/tic_tac_toe_factory.h>

namespace sophia::examples::tic_tac_toe::model_tests
{
    using std::dynamic_pointer_cast;
    using std::shared_ptr;
    using std::make_shared;
    using std::vector;

    class TicTacToeModelsFixture : public ::testing::Test
    {
    };

    TEST_F(TicTacToeModelsFixture, test)
    {
        const auto factory = make_shared<factories::TicTacToeFactory>();

        auto node = factory->CreateNode("S0");

        auto value = node->Value();

        EXPECT_EQ(1,1);
    }
}

