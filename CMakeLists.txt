cmake_minimum_required(VERSION 3.5)
project(P2 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Replace with all files in folder
set(SOURCE maze.cpp maze.h mouse.cpp mouse.h test_maze.cpp)

# create unittests
#Name before catch.hpp is user chosen: can't be the same name as any other file
add_executable(test-maze catch.hpp ${SOURCE})

enable_testing()

# unit tests
#Use this when there are multiple tests
add_test(test-mouse test-maze)