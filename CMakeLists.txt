cmake_minimum_required(VERSION 3.20)
project(matching-engine CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_compile_options(-Wall -Wextra -Werror)

option(SANITIZE "Build with ASan/UBSan" OFF)
if(SANITIZE)
  add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
  add_link_options(-fsanitize=address,undefined)
endif()

# Engine library
add_library(engine src/order_book.cpp)
target_include_directories(engine PUBLIC include)

# Replay program
add_executable(replay src/main.cpp)
target_link_libraries(replay PRIVATE engine)

# Tests
include(FetchContent)
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.zip)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(tests tests/test_order_book.cpp)
target_link_libraries(tests PRIVATE engine GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(tests)