add_library(sophia_monte_carlo_examples_tic_tac_toe_models
        state.cpp
        board.cpp
        position.cpp
        move.cpp
)

target_link_libraries(sophia_monte_carlo_examples_tic_tac_toe_models
        sophia_monte_carlo)

target_include_directories(sophia_monte_carlo_examples_tic_tac_toe_models
        PUBLIC
        ${CMAKE_SOURCE_DIR}/examples/monte_carlo/tic_tac_toe/include
        ${CMAKE_SOURCE_DIR}/include)