cmake_minimum_required(VERSION 3.16)

project(laba_n1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(laba_n1_lib
    src/str_ops.cpp
)

target_include_directories(laba_n1_lib PUBLIC
    src
)

add_executable(laba_oop_s3_n1
    main.cpp
)

target_link_libraries(laba_oop_s3_n1
    laba_n1_lib
)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(laba_n1_tests
    tests/test.cpp
)

target_link_libraries(laba_n1_tests
    laba_n1_lib
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(laba_n1_tests)