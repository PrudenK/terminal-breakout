cmake_minimum_required(VERSION 4.0)
project(terminal_breakout)

set(CMAKE_CXX_STANDARD 20)

add_executable(terminal_breakout main.cpp
        utils/constants.h)
