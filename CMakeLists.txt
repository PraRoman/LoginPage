cmake_minimum_required(VERSION 3.16)
project(LoginPage)

set(CMAKE_CXX_STANDARD 17)

# Указать исходники
include_directories(includes)

add_executable(LoginPage
    src/LoginPage.cpp
    src/Auth.cpp
    src/Utils.cpp
)

# ===== Google Test =====
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(LoginTests
    tests/test_login.cpp
)

target_link_libraries(LoginTests gtest_main)

include(GoogleTest)
gtest_discover_tests(LoginTests)
