#include <unistd.h>

#include "board/Board.h"
#include "keyboard/KeyboardManager.h"
#include "player/Player.h"
#include "utils/constants.h"

int main() {
    set_terminal_without_buffer();

    Board board(WIDTH, HEIGHT);
    board.init();
    Player player(INITIAL_PLAYER_POS, board);

    while (true) {
        int dir = read_last_direction();
        if (dir != 0) {
            player.move(dir);
        }

        board.print();
        usleep(60000);
    }
}