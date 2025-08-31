#include <gtest/gtest.h>
#include <tic_tac_toe/factories/tic_tac_toe_factory.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/tree_search_algorithm.h>
#include <tic_tac_toe/models/bot.h>

namespace sophia::examples::tic_tac_toe::model_tests
{
    using std::dynamic_pointer_cast;
    using std::shared_ptr;
    using std::make_shared;
    using std::vector;

    class TicTacToeModelsFixture : public ::testing::Test
    {
    };

    TEST_F(TicTacToeModelsFixture, simulation_test)
    {
        auto bot = std::make_shared<models::Bot>(Symbol::X);
        const auto factory = make_shared<factories::TicTacToeFactory>(bot);

        auto node = factory->CreateNode("S0");

        monte_carlo::tree_search_algorithm(node, 10);

        EXPECT_EQ(1,1);
    }
}

