cmake_minimum_required(VERSION 3.14)
project(LoginPage)

# Включаем FetchContent
include(FetchContent)

# Скачиваем Google Test
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Включаем поддержку тестов
enable_testing()

# Указываем исходники приложения
add_executable(LoginPage
  src/LoginPage.cpp
  src/Auth.cpp
  src/Utils.cpp
)

# Указываем исходники тестов
add_executable(LoginTests
  tests/LoginTests.cpp
)

# Линкуем GoogleTest
target_link_libraries(LoginTests
  gtest_main
)

# Указываем CMake запускать тесты
include(GoogleTest)
gtest_discover_tests(LoginTests)
