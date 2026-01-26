//
// Created by pruden on 26/1/26.
//

#ifndef TERMINAL_BREAKOUT_BOARD_H
#define TERMINAL_BREAKOUT_BOARD_H
#include <vector>


class Board {
    int width;
    int height;
    std::vector<std::vector<int>> board;

public: Board(int width, int height);
        void init();
        void print();

private:
    void print_cell(int value) const;

};


#endif //TERMINAL_BREAKOUT_BOARD_H