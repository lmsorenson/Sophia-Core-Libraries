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
add_executable(sophia_monte_carlo_tree_search_algorithm_tests
        tree_search_algorithm_tests.cpp
        mock_node.h
        mock_action.h)
target_link_libraries(sophia_monte_carlo_tree_search_algorithm_tests gtest gtest_main gmock gmock_main sophia_monte_carlo)
target_include_directories(sophia_monte_carlo_tree_search_algorithm_tests PUBLIC ../../../include)

add_test(NAME tree_search_algorithm_test COMMAND sophia_monte_carlo_library_tests)