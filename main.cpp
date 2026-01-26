#include <iostream>
#include <unistd.h>

#include "board/Board.h"
#include "keyboard/KeyboardManager.h"
#include "player/Player.h"
#include "utils/constants.h"

int main() {
    srand(time(NULL));

    set_terminal_without_buffer();


    Board board(WIDTH, HEIGHT);
    board.init();
    Player player(INITIAL_PLAYER_POS, board);
    board.print();

    while (true) {
        manage_keyboard_inputs(player);

        usleep(100000);
    }

    return 0;
}
