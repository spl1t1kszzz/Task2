cmake_minimum_required(VERSION 3.28)
project(poissonsoft_test)

set(CMAKE_CXX_STANDARD 20)

add_executable(poissonsoft_test main.cpp
        Point/Point.cpp
        Point/Point.h
        Segment/Segment.cpp
        Segment/Segment.h
        Polygon/Polygon.cpp
        Polygon/Polygon.h
        SymmetryAxisesFinder/SymmetryAxisesFinder.cpp
        SymmetryAxisesFinder/SymmetryAxisesFinder.h
)
