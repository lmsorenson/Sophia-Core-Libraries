add_library(sophia_monte_carlo_models
        action.cpp
        node.cpp
        random_action_strategy.cpp)

target_include_directories(sophia_monte_carlo_models PUBLIC ../../../include)