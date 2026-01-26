#include <iostream>

#include "board/Board.h"
#include "utils/constants.h"

int main() {

    Board board(WIDTH, HEIGHT);
    board.init();
    board.print();


    return 0;
}
