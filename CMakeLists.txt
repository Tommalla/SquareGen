cmake_minimum_required(VERSION 2.8.9)

project(SquareGen)

set (CMAKE_CXX_FLAGS "-Wall -std=c++11 -ggdb")
set (EXECUTABLE_OUTPUT_PATH "${SquareGen_BINARY_DIR}/bin")

add_subdirectory(src)