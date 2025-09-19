include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(sophia_monte_carlo_examples_tic_tac_toe_tests
    simulation_tests.cpp)
target_link_libraries(sophia_monte_carlo_examples_tic_tac_toe_tests
        gtest gtest_main
        gmock gmock_main
        sophia_monte_carlo_examples_tic_tac_toe)
target_include_directories(sophia_monte_carlo_examples_tic_tac_toe_tests
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include)

add_test(NAME simulation_test COMMAND sophia_monte_carlo_examples_tic_tac_toe_tests)

add_subdirectory(model_tests)