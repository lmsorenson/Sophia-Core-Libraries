add_library(sophia_monte_carlo_examples_tic_tac_toe)
target_link_libraries(sophia_monte_carlo_examples_tic_tac_toe sophia_monte_carlo)
target_include_directories(sophia_monte_carlo_examples_tic_tac_toe
        PUBLIC
        ${CMAKE_SOURCE_DIR}/examples/monte_carlo/tic_tac_toe/include
        ${CMAKE_SOURCE_DIR}/include
)

add_subdirectory(factories)
add_subdirectory(models)

add_executable(tic_tac_toe_game main.cpp)
target_link_libraries(tic_tac_toe_game
        sophia_monte_carlo_examples_tic_tac_toe)
target_include_directories(tic_tac_toe_game
        PUBLIC
        ${CMAKE_SOURCE_DIR}/examples/monte_carlo/tic_tac_toe/include
        ${CMAKE_SOURCE_DIR}/include
)