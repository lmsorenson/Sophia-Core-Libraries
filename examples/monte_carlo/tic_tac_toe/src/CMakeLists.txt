add_library(sophia_monte_carlo_examples_tic_tac_toe)

target_link_libraries(sophia_monte_carlo_examples_tic_tac_toe
        sophia_monte_carlo)

message(STATUS "Project root directory: ${CMAKE_SOURCE_DIR}")
target_include_directories(sophia_monte_carlo_examples_tic_tac_toe
        PUBLIC
        ${CMAKE_SOURCE_DIR}/examples/monte_carlo/tic_tac_toe/include
        ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(factories)
add_subdirectory(models)