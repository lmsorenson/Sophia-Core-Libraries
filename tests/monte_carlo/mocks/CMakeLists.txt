include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(sophia_monte_carlo_mocks
)

target_link_libraries(sophia_monte_carlo_mocks
        gmock gmock_main
        sophia_monte_carlo)
target_include_directories(sophia_monte_carlo_mocks
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/tests/monte_carlo/mocks/include)

add_subdirectory(include)
add_subdirectory(src)