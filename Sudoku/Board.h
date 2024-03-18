#ifndef BOARD_H
#define BOARD_H

#include <iostream>

const int BOARD_SIZE = 9;

class Board {
private:
    int grid[BOARD_SIZE][BOARD_SIZE];
    bool editable[BOARD_SIZE][BOARD_SIZE];

public:
    Board();
    void generateBoard();
    void displayBoard();
    bool isValidMove(int row, int col, int num);
    void placeNumber(int row, int col, int num);
    bool isBoardFull();
    bool isCellEditable(int row, int col);
};

#endif
