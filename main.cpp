#include <iostream>

#include "board/Board.h"
#include "player/Player.h"
#include "utils/constants.h"

int main() {

    Board board(WIDTH, HEIGHT);
    board.init();
    board.print();

    Player player(INITIAL_PLAYER_POS, board);

    player.move(-1);

    return 0;
}
