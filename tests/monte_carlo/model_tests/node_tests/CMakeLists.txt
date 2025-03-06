target_sources(sophia_monte_carlo_tests
        PUBLIC
        backpropagate_tests.cpp
        expand_tests.cpp
        has_been_sampled_tests.cpp
        is_leaf_node_tests.cpp
        name_tests.cpp
        rollout_tests.cpp
        select_best_action_tests.cpp
        set_parent_tests.cpp
        total_reward_tests.cpp
        upper_confidence_bound_tests.cpp
        value_tests.cpp
        visit_count_tests.cpp)

add_test(NAME node_backpropagate_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_expand_with_no_available_actions_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_expand_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_has_been_sampled_false_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_is_leaf_node_false_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_is_leaf_node_true_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_name_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_rollout_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_rollout_2_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_select_best_action_no_scores_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_select_best_action_choose_node_with_no_scores_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_select_best_action_choose_node_with_best_scores_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_set_parent_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_total_reward_default_value_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_total_reward_with_non_default_value_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_upper_confidence_bound_infinity_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_upper_confidence_bound_value_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_value_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_visit_count_default_value_test COMMAND sophia_monte_carlo_tests)
add_test(NAME node_visit_count_with_non_default_value_test COMMAND sophia_monte_carlo_tests)