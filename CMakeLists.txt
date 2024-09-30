cmake_minimum_required(VERSION 3.29)
project(ListTest)

set(CMAKE_CXX_STANDARD 20)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(ListTest list_test.cpp
        src/List.cpp
        src/List.h)
