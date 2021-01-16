cmake_minimum_required(VERSION 3.17)
project(pthread)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES source/methods.cpp)

add_executable(pthread main.cpp ${SOURCE_FILES})