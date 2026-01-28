#include <unistd.h>

#include "ball/Ball.h"
#include "board/Board.h"
#include "keyboard/KeyboardManager.h"
#include "player/Player.h"
#include "utils/constants.h"

int main() {
    set_terminal_without_buffer();

    Board board(WIDTH, HEIGHT);
    Player player(INITIAL_PLAYER_POS);
    Ball ball;

    while (true) {
        if (!player.get_game_over()) {
            int dir = read_last_direction(player, board, ball);
            if (dir != 0) {
                player.move(dir, board);
            }
            player.update_last_dir();
            ball.update(player, board);
            board.print(player);
        }else {
            read_last_direction(player, board, ball);
        }

        usleep(60000);
    }
}