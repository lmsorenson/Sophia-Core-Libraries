cmake_minimum_required(VERSION 3.29)
project(Sophia_Decision_Engine)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(examples)
add_subdirectory(include)
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)