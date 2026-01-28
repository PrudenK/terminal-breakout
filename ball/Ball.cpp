//
// Created by pruden on 27/1/26.
//

#include "Ball.h"

#include "../player/Player.h"
#include "../utils/constants.h"
#include "../board/Board.h"

Ball::Ball(): x(HEIGHT - OFFSET_BALL_X_START), y(WIDTH / 2), dx(1), dy(0), tick_counter(0), restart_tick_counter(0) {}


void Ball::update(Player& player, Board& board) {
    if (restart_tick_counter > 0) {
        restart_tick_counter--;
        return;
    }

    bool ball_restart = false;

    tick_counter++;
    if (tick_counter < 2) return;
    tick_counter = 0;

    board.set_cell(x, y, EMPTY);

    int nextX = x + dx;
    int nextY = y + dy;

    int cellX = board.getCell(nextX, y);
    int cellY = board.getCell(x, nextY);

    bool moveX = true;
    bool moveY = true;

    if (cellX != EMPTY) {
        moveX = false;

        if (cellX == PLAYER) {
            dx = -1;
            dy = player.get_last_dir();
        } else if (cellX >= BORDER_TOP && cellX <= BORDER_BOTTOM) {
            if (cellX == BORDER_BOTTOM) {
                ball_restart = true;
            }else {
                dx *= -1;
            }
        } else if (cellX > 100) {
            if (cellX == GREEN_BLOCK) board.set_cell(nextX, y, EMPTY);
            else board.set_cell(nextX, y, cellX - 1);
            dx *= -1;
        }
    }

    if (cellY != EMPTY && !ball_restart) {
        moveY = false;

        if (cellY == PLAYER) {
            dx = -1;
            dy = player.get_last_dir();
        } else if (cellY >= BORDER_TOP && cellY <= BORDER_BOTTOM) {
            if (cellY == BORDER_BOTTOM) {
                ball_restart = true;
            }else {
                dy *= -1;
            }
        } else if (cellY > 100) {
            if (cellY == GREEN_BLOCK) board.set_cell(x, nextY, EMPTY);
            else board.set_cell(x, nextY, cellY - 1);
            dy *= -1;
        }
    }

    if (!ball_restart) {
        int newX = x;
        int newY = y;

        if (moveX && board.getCell(x + dx, y) == EMPTY) newX += dx;
        if (moveY && board.getCell(newX, y + dy) == EMPTY) newY += dy;

        x = newX;
        y = newY;

        board.set_cell(x, y, BALL);
    }else {
        restart(player, board);
    }
}

void Ball::restart(Player& player, Board& board) {
    player.lost_live();

    int lives = player.get_lives();

    if (lives == 0) {

    }else{
        x = HEIGHT - OFFSET_BALL_X_START;
        y = WIDTH / 2;
        dx = 1;
        dy = 0;
        board.set_cell(HEIGHT - OFFSET_BALL_X_START, WIDTH / 2, BALL);
        restart_tick_counter = 30;
    }
}
