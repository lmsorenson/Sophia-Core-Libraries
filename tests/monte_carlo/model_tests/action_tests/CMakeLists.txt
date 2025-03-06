target_sources(sophia_monte_carlo_tests
        PUBLIC
        action_source_tests.cpp
        action_target_tests.cpp
        action_upper_confidence_bound_tests.cpp)

add_test(NAME action_source_test COMMAND sophia_monte_carlo_tests)
add_test(NAME action_source_null_test COMMAND sophia_monte_carlo_tests)
add_test(NAME action_target_test COMMAND sophia_monte_carlo_tests)
add_test(NAME action_target_null_test COMMAND sophia_monte_carlo_tests)
add_test(NAME action_upper_confidence_bound_null_nodes_test COMMAND sophia_monte_carlo_tests)
add_test(NAME action_upper_confidence_bound_infinity_test COMMAND sophia_monte_carlo_tests)
add_test(NAME action_upper_confidence_bound_value_test COMMAND sophia_monte_carlo_tests)