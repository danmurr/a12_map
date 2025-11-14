cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(dsac)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/catch2)

add_executable(
    my_exec
    src/main.cpp
    src/box_optimizer.cpp
    src/cart_analysis.cpp
    src/customer_loyalty.cpp
    src/api_monitor.cpp
)

add_executable(
    my_test
    tests/test.cpp
    src/box_optimizer.cpp
    src/cart_analysis.cpp
    src/customer_loyalty.cpp
    src/api_monitor.cpp
)

target_include_directories(my_test PRIVATE include)

enable_testing()
add_test(NAME my_test COMMAND my_test)