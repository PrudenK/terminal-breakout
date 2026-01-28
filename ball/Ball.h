//
// Created by pruden on 27/1/26.
//

#ifndef TERMINAL_BREAKOUT_BALL_H
#define TERMINAL_BREAKOUT_BALL_H
#include "../player/Player.h"

class Ball {
    int x;
    int y;
    int dx;
    int dy;
    int tick_counter;
    int restart_tick_counter;


public:
    Ball();
    void update(Player& player, Board& board);

    void restart(Player &player, Board &board);

    void ball_reset(Board &board);
};


#endif //TERMINAL_BREAKOUT_BALL_H