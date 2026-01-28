//
// Created by pruden on 26/1/26.
//

#ifndef TERMINAL_BREAKOUT_KEYBOARDMANAGER_H
#define TERMINAL_BREAKOUT_KEYBOARDMANAGER_H
#include "../ball/Ball.h"
#include "../board/Board.h"
#include "../player/Player.h"

void set_terminal_without_buffer();
void restore_terminal();
int read_last_direction(Player& player, Board& board, Ball& ball);


#endif //TERMINAL_BREAKOUT_KEYBOARDMANAGER_H