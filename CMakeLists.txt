cmake_minimum_required(VERSION 3.20)

project(hbench)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
    hbench
    src/main.cpp
    src/timer.cpp
)