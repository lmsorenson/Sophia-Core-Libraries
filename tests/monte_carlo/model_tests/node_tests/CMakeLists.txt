include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(sophia_monte_carlo_model_tests
        name_tests.cpp
        set_parent_tests.cpp
        total_reward_tests.cpp
        value_tests.cpp
        visit_count_tests.cpp)
target_link_libraries(sophia_monte_carlo_model_tests
        gtest gtest_main
        gmock gmock_main
        sophia_monte_carlo
        sophia_monte_carlo_mocks)
target_include_directories(sophia_monte_carlo_model_tests PUBLIC ../../../../include)

add_test(NAME node_name_test COMMAND sophia_monte_carlo_model_tests)
add_test(NAME node_set_parent_test COMMAND sophia_monte_carlo_model_tests)
add_test(NAME node_total_reward_default_value_test COMMAND sophia_monte_carlo_model_tests)
add_test(NAME node_total_reward_with_non_default_value_test COMMAND sophia_monte_carlo_model_tests)
add_test(NAME node_value_test COMMAND sophia_monte_carlo_model_tests)
add_test(NAME node_visit_count_default_value_test COMMAND sophia_monte_carlo_model_tests)
add_test(NAME node_visit_count_with_non_default_value_test COMMAND sophia_monte_carlo_model_tests)