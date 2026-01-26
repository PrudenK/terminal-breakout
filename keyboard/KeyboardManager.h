//
// Created by pruden on 26/1/26.
//

#ifndef TERMINAL_BREAKOUT_KEYBOARDMANAGER_H
#define TERMINAL_BREAKOUT_KEYBOARDMANAGER_H

void set_terminal_without_buffer();
void restore_terminal();
int read_last_direction();


#endif //TERMINAL_BREAKOUT_KEYBOARDMANAGER_H