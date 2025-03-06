target_sources(sophia_monte_carlo_examples_tic_tac_toe_tests
        PUBLIC
        state_tests.cpp)

add_test(NAME test COMMAND sophia_monte_carlo_examples_tic_tac_toe_tests)