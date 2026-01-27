//
// Created by pruden on 27/1/26.
//

#include "Ball.h"

#include "../player/Player.h"
#include "../utils/constants.h"

Ball::Ball(): x(HEIGHT - OFFSET_BALL_X_START), y(WIDTH / 2), dx(1), dy(0), tick_counter(0) {}


void Ball::update(Player& player, Board& board) {
    tick_counter++;
    if (tick_counter < 2) return;
    tick_counter = 0;


    board.set_cell(x, y, EMPTY);
    int tempX = x + dx;
    int tempY = y + dy;


    int colisionCell = board.getCell(tempX, tempY);

    if (colisionCell == EMPTY) {
        x += dx;
        y += dy;

        board.set_cell(x, y, BALL);
    }else {
        if (colisionCell == PLAYER) {
            dx = -1;
            dy = player.get_last_dir();
            update_cell(board);
        }else {
            switch (colisionCell) {
                case BORDER_LEFT:
                case BORDER_RIGHT:
                    dy *= -1;
                    update_cell(board);
                    break;
                default:
                    dx *= -1;
                    update_cell(board);
                    break;
            }
        }
    }
}

void Ball::update_cell(Board& board) {
    x += dx;
    y += dy;

    board.set_cell(x, y, BALL);
}
