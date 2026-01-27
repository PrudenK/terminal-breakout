//
// Created by pruden on 26/1/26.
//

#ifndef TERMINAL_BREAKOUT_CONSTANTS_H
#define TERMINAL_BREAKOUT_CONSTANTS_H

constexpr int WIDTH = 15;
constexpr int HEIGHT = 22;

constexpr int EMPTY = 0;
constexpr int PLAYER = 1;
constexpr int BULLET = 11;
constexpr int BALL = 8;
constexpr int OFFSET_BALL_X_START = 10;

constexpr int INITIAL_PLAYER_POS = WIDTH / 2;



constexpr int DIR_LEFT = -1;
constexpr int DIR_RIGHT = 1;


constexpr int LIMIT_LEFT = 2;
constexpr int LIMIT_RIGHT = WIDTH - 3;

// Blocks
constexpr int RED_BLOCK = 6;
constexpr int ORANGE_BLOCK = 5;
constexpr int YELLOW_BLOCK = 4;
constexpr int BLUE_BLOCK = 3;
constexpr int GREEN_BLOCK = 2;

// BORDERS
constexpr int BORDER_TOP = 91;
constexpr int BORDER_LEFT = 92;
constexpr int BORDER_RIGHT = 93;
constexpr int BORDER_BOTTOM = 94;



#endif //TERMINAL_BREAKOUT_CONSTANTS_H