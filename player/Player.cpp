//
// Created by pruden on 26/1/26.
//

#include "Player.h"
#include "../utils/constants.h"

Player::Player(int pos, Board& board): pos(pos), board(board) {}



void Player::move(int dir) {
    if (dir == DIR_RIGHT) {
        if (this->pos < LIMIT_RIGHT) {
            this->pos += DIR_RIGHT;
            this->update_pos();
        }
    }else if (dir == DIR_LEFT) {
        if (this->pos > LIMIT_LEFT) {
            this->pos += DIR_LEFT;
            this->update_pos();
        }
    }
}

void Player::update_pos() {
    for (int i = 1; i < WIDTH -1; ++i) {
        this->board.set_cell(HEIGHT - 2, i, EMPTY);
    }

    this->board.set_cell(HEIGHT - 2, pos - 1, PLAYER);
    this->board.set_cell(HEIGHT - 2, pos, PLAYER);
    this->board.set_cell(HEIGHT - 2, pos + 1, PLAYER);
}