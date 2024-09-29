cmake_minimum_required(VERSION 3.28)
project(poissonsoft_test)

set(CMAKE_CXX_STANDARD 20)

add_library(task_2_lib
        Point/Point.cpp
        Point/Point.h
        Segment/Segment.cpp
        Segment/Segment.h
        Polygon/Polygon.cpp
        Polygon/Polygon.h
        SymmetryAxisesFinder/SymmetryAxisesFinder.cpp
        SymmetryAxisesFinder/SymmetryAxisesFinder.h
)

add_executable(task2 main.cpp)

target_link_libraries(task2 task_2_lib)

add_subdirectory(googletest)

enable_testing()
add_executable(task_2_tests
        test/test_main.cpp
        test/test_symmetry_axises_finder.cpp
)

target_link_libraries(task_2_tests gtest gtest_main task_2_lib)
