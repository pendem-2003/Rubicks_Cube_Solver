cmake_minimum_required(VERSION 3.28)
project(Rubicks_Cube_Solver)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rubicks_Cube_Solver main.cpp
        Rubickscube.cpp
        Rubickscube.h)
