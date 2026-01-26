//
// Created by pruden on 26/1/26.
//

#include "KeyboardManager.h"

#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <cstdio>
#include <cstdlib>

#include "../player/Player.h"
#include "../utils/constants.h"


void set_terminal_without_buffer() {
    termios t{};
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void restore_terminal() {
    termios t{};
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void manage_keyboard_inputs(Player& player) {
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    timeval timeout{};
    timeout.tv_sec = 0;
    timeout.tv_usec = 1000;

    if (select(STDIN_FILENO + 1, &read_fds, nullptr, nullptr, &timeout) > 0) {
        char c = getchar();

        if (c == '\033') {
            getchar();
            c = getchar();

            if (c == 'C') {
                player.move(DIR_RIGHT);
            } else if (c == 'D') {
                player.move(DIR_LEFT);
            }
        }

        if (c == 'q') {
            printf("Saliendo...\n");
            restore_terminal();
            exit(0);
        }
    }
}
