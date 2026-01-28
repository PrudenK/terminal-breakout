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
    bool game_over;

public:
    Player(int pos);

    void move(int dir, Board& board);

    void update_pos(Board& board);

    void update_last_dir();

    int get_lives();

    void set_lives(int l);

    void lost_live();

    int get_last_dir();

    int get_pos();

    void restart_pos();

    bool get_game_over();

    void set_game_over(bool b);
};


#endif //TERMINAL_BREAKOUT_PLAYER_H