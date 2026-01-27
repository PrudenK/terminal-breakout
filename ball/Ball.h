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


public:
    Ball();
    void update(Player& player, Board& board);

private:
    void update_cell(Board &board);
};


#endif //TERMINAL_BREAKOUT_BALL_H