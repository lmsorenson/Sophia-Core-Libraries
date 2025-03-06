add_library(sophia_monte_carlo
        tree_search_algorithm.cpp
        ../../include/monte_carlo/models/node_base.tpp)

add_subdirectory(models)

target_include_directories(sophia_monte_carlo
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src)