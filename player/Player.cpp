//
// Created by pruden on 26/1/26.
//

#include "Player.h"
#include "../utils/constants.h"

Player::Player(int pos, Board& board): pos(pos), board(board) {}



void Player::move(int dir) {
    if (dir == DIR_RIGHT) {
        if (this->pos > LIMIT_RIGHT) {
            this->pos += DIR_RIGHT;
        }
    }else if (dir == DIR_LEFT) {
        if (this->pos > LIMIT_LEFT) {
            this->pos += DIR_LEFT;
        }
    }

    board.print();
}