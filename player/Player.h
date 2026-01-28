//
// Created by pruden on 26/1/26.
//

#ifndef TERMINAL_BREAKOUT_PLAYER_H
#define TERMINAL_BREAKOUT_PLAYER_H
class Board;


class Player {
    int pos;
    int last_dir;
    int tick_count;
    int lives;

public:
    Player(int pos);

    void move(int dir, Board& board);

    void update_pos(Board& board);

    void update_last_dir();

    int get_lives();

    void lost_live();

    int get_last_dir();

    int get_pos();
};


#endif //TERMINAL_BREAKOUT_PLAYER_H