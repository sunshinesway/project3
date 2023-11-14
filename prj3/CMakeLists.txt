cmake_minimum_required(VERSION 3.25)
project(prj3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(prj3
        data_structures.h
        graph.cpp
        graph.h
        heap.cpp
        heap.h
        main.cpp
        stack.cpp
        stack.h
        util.cpp
        util.h)
