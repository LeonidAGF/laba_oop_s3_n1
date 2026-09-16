
cmake_minimum_required(VERSION 3.16)

project(my_test_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    laba_oop_s3_n1
    laba_oop_s3_n1.cpp
    laba_oop_s3_n1.h
    str_ops.cpp
    str_ops.h
)

target_link_libraries(
    laba_oop_s3_n1
    PRIVATE
    GTest::gtest_main
)

include(GoogleTest)

#gtest_discover_tests(laba_oop_s3_n1)