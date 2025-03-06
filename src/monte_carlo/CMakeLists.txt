add_library(sophia_monte_carlo
        tree_search_algorithm.cpp)

add_subdirectory(models)

target_include_directories(sophia_monte_carlo PUBLIC ../../include)