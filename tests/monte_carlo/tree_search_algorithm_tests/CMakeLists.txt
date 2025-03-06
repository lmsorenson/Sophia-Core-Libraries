target_sources(sophia_monte_carlo_tests
    PUBLIC
        tree_search_algorithm_tests.cpp
    )

add_test(NAME tree_search_algorithm_test COMMAND sophia_monte_carlo_tests)