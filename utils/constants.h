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
constexpr int BORDER = 9;

constexpr int INITIAL_PLAYER_POS = WIDTH / 2;



constexpr int DIR_LEFT = -1;
constexpr int DIR_RIGHT = 1;


constexpr int LIMIT_LEFT = 2;
constexpr int LIMIT_RIGHT = WIDTH - 3;

#endif //TERMINAL_BREAKOUT_CONSTANTS_H