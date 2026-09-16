
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
    main.cpp
    src/str_ops.cpp
    src/str_ops.h
)

#add_executable(
#    str_tests
#    tests/test_alloc.cpp
#    tests/test_len.cpp
#    tests/test_main.cpp
#    tests/test_pressure.cpp
#    tests/test_str_copy.cpp
#    tests/test_str_count_char.cpp
#    tests/test_str_delete.cpp
#    tests/test_str_input.cpp
#    tests/test_str_print.cpp
#    tests/test_str_to_upper.cpp
#)

target_link_libraries(
    laba_oop_s3_n1
    PRIVATE
    GTest::gtest_main
)

include(GoogleTest)

#gtest_discover_tests(str_tests)