add_library(sophia_monte_carlo_examples_tic_tac_toe_factories
        tic_tac_toe_factory.cpp)

target_link_libraries(sophia_monte_carlo_examples_tic_tac_toe_factories
        sophia_monte_carlo)

message(STATUS "Project root directory: ${CMAKE_SOURCE_DIR}")
target_include_directories(sophia_monte_carlo_examples_tic_tac_toe_factories
        PUBLIC
        ${CMAKE_SOURCE_DIR}/examples/monte_carlo/tic_tac_toe/include
        ${CMAKE_SOURCE_DIR}/include)