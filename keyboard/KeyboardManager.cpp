//
// Created by pruden on 26/1/26.
//

#include "KeyboardManager.h"

#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <cstdio>
#include <cstdlib>

#include "../ball/Ball.h"
#include "../board/Board.h"
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

int read_last_direction(Player& player, Board& board, Ball& ball) {
    fd_set read_fds;
    timeval timeout{};
    int last_dir = 0;

    while (true) {
        FD_ZERO(&read_fds);
        FD_SET(STDIN_FILENO, &read_fds);

        timeout.tv_sec = 0;
        timeout.tv_usec = 0;

        if (select(STDIN_FILENO + 1, &read_fds, nullptr, nullptr, &timeout) <= 0)
            break;

        char c = getchar();

        if (c == '\033') {
            char c1 = getchar();
            if (c1 != '[') {
                restore_terminal();
                exit(0);
            }

            char c2 = getchar();
            if (c2 == 'C') last_dir = DIR_RIGHT;
            else if (c2 == 'D') last_dir = DIR_LEFT;

        } else if (c == 'q') {
            restore_terminal();
            exit(0);

        } else if (c == 'r') {
            player.set_game_over(false);
            player.set_lives(3);
            player.restart_pos();
            board.init();
            ball.ball_reset(board);
        }
    }

    return last_dir;
}
