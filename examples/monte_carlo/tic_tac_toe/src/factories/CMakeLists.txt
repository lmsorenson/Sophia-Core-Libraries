add_library(sophia_monte_carlo_examples_tic_tac_toe_factories
        tic_tac_toe_factory.cpp)

target_link_libraries(sophia_monte_carlo_examples_tic_tac_toe_factories
        sophia_monte_carlo
        sophia_monte_carlo_factories
        sophia_monte_carlo_models
        )

target_include_directories(sophia_monte_carlo_examples_tic_tac_toe_factories
        PUBLIC
        ../../include
        ../../../../../include)