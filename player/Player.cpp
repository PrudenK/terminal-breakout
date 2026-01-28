//
// Created by pruden on 26/1/26.
//

#include "Player.h"
#include "../utils/constants.h"
#include "../board/Board.h"

Player::Player(int pos): pos(pos), last_dir(0), tick_count(0), lives(3) {}



void Player::move(int dir, Board& board) {
    if (dir == DIR_RIGHT && pos < LIMIT_RIGHT) {
        pos += DIR_RIGHT;
        last_dir = DIR_RIGHT;
        tick_count = 0;
        update_pos(board);
    } else if (dir == DIR_LEFT && pos > LIMIT_LEFT) {
        pos += DIR_LEFT;
        last_dir = DIR_LEFT;
        tick_count = 0;
        update_pos(board);
    }
}

void Player::update_pos(Board& board) {
    for (int i = 1; i < WIDTH -1; ++i) {
        board.set_cell(HEIGHT + PLAYER_POS_Y_OFFSET, i, EMPTY);
    }

    board.set_cell(HEIGHT + PLAYER_POS_Y_OFFSET, pos - 1, PLAYER);
    board.set_cell(HEIGHT + PLAYER_POS_Y_OFFSET, pos, PLAYER);
    board.set_cell(HEIGHT + PLAYER_POS_Y_OFFSET, pos + 1, PLAYER);
}

void Player::update_last_dir() {
    tick_count++;
    if (tick_count % 5 != 0) return;
    tick_count = 0;

    last_dir = 0;
}

int Player::get_lives() {
    return this->lives;
}

void Player::lost_live() {
    this->lives--;
}

int Player::get_last_dir() {
    return last_dir;
}

int Player::get_pos() {
    return pos;
}