//
// Created by pruden on 26/1/26.
//

#include "Player.h"
#include "../utils/constants.h"

Player::Player(int pos, Board& board): pos(pos), board(board), last_dir(0), tick_count(0) {}



void Player::move(int dir) {
    if (dir == DIR_RIGHT && pos < LIMIT_RIGHT) {
        pos += DIR_RIGHT;
        last_dir = DIR_RIGHT;
        tick_count = 0;
        update_pos();
    } else if (dir == DIR_LEFT && pos > LIMIT_LEFT) {
        pos += DIR_LEFT;
        last_dir = DIR_LEFT;
        tick_count = 0;
        update_pos();
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

void Player::update_last_dir() {
    tick_count++;
    if (tick_count % 5 != 0) return;
    tick_count = 0;

    last_dir = 0;
}

int Player::get_last_dir() {
    return last_dir;
}

int Player::get_pos() {
    return pos;
}