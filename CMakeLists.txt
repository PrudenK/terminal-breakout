cmake_minimum_required(VERSION 3.20)
project(terminal_breakout)

set(CMAKE_CXX_STANDARD 20)

add_executable(terminal_breakout main.cpp
        utils/constants.h
        board/Board.cpp
        board/Board.h
        player/Player.cpp
        player/Player.h
        keyboard/KeyboardManager.cpp
        keyboard/KeyboardManager.h)
