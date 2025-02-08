add_library(sophia_monte_carlo library.cpp)

# Link it to the main library
#target_link_libraries(sophia_monte_carlo PUBLIC sophia)
target_include_directories(sophia_monte_carlo PUBLIC ../../include)