//
// Created by pruden on 26/1/26.
//

#ifndef TERMINAL_BREAKOUT_PLAYER_H
#define TERMINAL_BREAKOUT_PLAYER_H
#include "../board/Board.h"


class Player {
    int pos;
    Board& board;
    int last_dir;
    int tick_count;

public:
    Player(int pos, Board& board);

    void move(int dir);

    void update_pos();

    void update_last_dir();

    int get_last_dir();

    int get_pos();
};


#endif //TERMINAL_BREAKOUT_PLAYER_H