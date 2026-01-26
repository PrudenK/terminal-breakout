//
// Created by pruden on 26/1/26.
//

#include "Board.h"

#include <cstdio>

#include "../utils/constants.h"


Board::Board(int width, int height): width(width), height(height), board(height, std::vector<int>(width)) {

}


void Board::init() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (j == 0 || j == WIDTH - 1) {
                board[i][j] = BORDER;
            }else if (i == 0 || i == HEIGHT - 1) {
                board[i][j] = BORDER;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }

    board[HEIGHT - 2][WIDTH / 2 - 1] = PLAYER;
    board[HEIGHT - 2][WIDTH / 2] = PLAYER;
    board[HEIGHT - 2][WIDTH / 2 + 1] = PLAYER;
}

void Board::print() {
    printf("\033[H\033[J\n\n");

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            print_cell(board[i][j]);
        }
        printf("\n");
    }
}

void Board::print_cell(int j) const {
    switch (j) {
        case EMPTY: printf("   "); break;
        case PLAYER: printf("\033[1;97m===\033[0m"); break;
        case BORDER: printf("\033[100m   \033[0m"); break;
        default: printf("\033[41m???\033[0m"); break;
    }
}
