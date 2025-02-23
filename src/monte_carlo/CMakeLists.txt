add_subdirectory(factories)
add_subdirectory(models)

add_library(sophia_monte_carlo
        tree_search_algorithm.cpp)

target_link_libraries(sophia_monte_carlo sophia_monte_carlo_factories sophia_monte_carlo_models)
target_include_directories(sophia_monte_carlo PUBLIC ../../include)