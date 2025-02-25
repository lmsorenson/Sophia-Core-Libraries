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
add_executable(sophia_monte_carlo_action_tests
        action_source_tests.cpp
        action_target_tests.cpp
        action_upper_confidence_bound_tests.cpp)
target_link_libraries(sophia_monte_carlo_action_tests
        gtest gtest_main
        gmock gmock_main
        sophia_monte_carlo
        sophia_monte_carlo_mocks)
target_include_directories(sophia_monte_carlo_action_tests PUBLIC ../../../../include)

add_test(NAME action_source_test COMMAND sophia_monte_carlo_action_tests)
add_test(NAME action_source_null_test COMMAND sophia_monte_carlo_action_tests)
add_test(NAME action_target_test COMMAND sophia_monte_carlo_action_tests)
add_test(NAME action_target_null_test COMMAND sophia_monte_carlo_action_tests)
add_test(NAME action_upper_confidence_bound_null_nodes_test COMMAND sophia_monte_carlo_action_tests)
add_test(NAME action_upper_confidence_bound_infinity_test COMMAND sophia_monte_carlo_action_tests)
add_test(NAME action_upper_confidence_bound_value_test COMMAND sophia_monte_carlo_action_tests)