add_library(sophia_monte_carlo tree_search_algorithm.cpp
        ../../include/monte_carlo/models/node.h
        ../../include/monte_carlo/models/action.h
        models/node.cpp
        models/action.cpp
        ../../include/monte_carlo/models/action_select_strategy_interface.h
        ../../include/monte_carlo/models/random_action_strategy.h
        models/random_action_strategy.cpp)

target_include_directories(sophia_monte_carlo PUBLIC ../../include)