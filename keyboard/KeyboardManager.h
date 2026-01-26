//
// Created by pruden on 26/1/26.
//

#ifndef TERMINAL_BREAKOUT_KEYBOARDMANAGER_H
#define TERMINAL_BREAKOUT_KEYBOARDMANAGER_H
#include "../player/Player.h"

void set_terminal_without_buffer();
void restore_terminal();
void manage_keyboard_inputs(Player& player);


#endif //TERMINAL_BREAKOUT_KEYBOARDMANAGER_H