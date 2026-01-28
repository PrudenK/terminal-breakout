//
// Created by pruden on 26/1/26.
//

#include "Board.h"

#include <cstdio>
#include <iostream>

#include "../utils/constants.h"
#include "../player/Player.h"


Board::Board(int width, int height): width(width), height(height), board(height, std::vector<int>(width)) {

}

void Board::set_cell(int x, int y, int value) {
    board[x][y] = value;
}

int Board::getCell(int x, int y) {
    return board[x][y];
}

void Board::init() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (j == 0) {
                board[i][j] = BORDER_LEFT;
            }else if (i == 0) {
                board[i][j] = BORDER_TOP;
            }else if (i == HEIGHT - 1) {
                board[i][j] = BORDER_BOTTOM;
            }else if (j == WIDTH - 1) {
                board[i][j] = BORDER_RIGHT;
            }else {
                switch (i) {
                    case 1: board[i][j] = RED_BLOCK; break;
                    case 2: board[i][j] = ORANGE_BLOCK; break;
                    case 3: board[i][j] = YELLOW_BLOCK; break;
                    case 4: board[i][j] = BLUE_BLOCK; break;
                    case 5: board[i][j] = GREEN_BLOCK; break;
                    default: board[i][j] = EMPTY; break;
                }
            }
        }
    }

    board[HEIGHT + PLAYER_POS_Y_OFFSET][WIDTH / 2 - 1] = PLAYER;
    board[HEIGHT + PLAYER_POS_Y_OFFSET][WIDTH / 2] = PLAYER;
    board[HEIGHT + PLAYER_POS_Y_OFFSET][WIDTH / 2 + 1] = PLAYER;
}

void Board::print(Player& player) {
    printf("\033[H\033[J\n\n");

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            print_cell(board[i][j]);
        }

        switch (i) {
            case 3:
                printf("   Developed by Pruden");
                break;
            case 4:
                printf("   On Github: ");
                break;
            case 6:
                printf("   Score: ");
                break;
            case 8:
                std::string lives;
                for (int k = 0; k < player.get_lives(); k++) {
                    lives += "♥ ";
                }
                std::cout << "   Lives: " << lives;
                break;
        }

        printf("\n");
    }
}

void Board::print_cell(int v) const {
    switch (v) {
        case EMPTY:        printf("   "); break;
        case PLAYER:       printf("\033[1;97m===\033[0m"); break;
        case BORDER_TOP:
        case BORDER_LEFT:
        case BORDER_BOTTOM:
        case BORDER_RIGHT:
            //std::cout << v << " ";
            printf("\033[100m   \033[0m");
            break;
        case RED_BLOCK:    printf("\033[41m   \033[0m"); break;
        case ORANGE_BLOCK: printf("\033[43m   \033[0m"); break;
        case YELLOW_BLOCK: printf("\033[103m   \033[0m"); break;
        case GREEN_BLOCK:  printf("\033[42m   \033[0m"); break;
        case BLUE_BLOCK:   printf("\033[44m   \033[0m"); break;
        case BALL:         printf("\033[1;97m ● \033[0m"); break;

        default:           printf("\033[41m???\033[0m"); break;
    }
}