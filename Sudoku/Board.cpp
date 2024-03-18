#include "board.h"

Board::Board() {
    generateBoard();
}

void Board::generateBoard() {
    // Initialize the Sudoku board
    int initialBoard[BOARD_SIZE][BOARD_SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // Copy the initial board and mark editable cells
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            grid[i][j] = initialBoard[i][j];
            editable[i][j] = (initialBoard[i][j] == 0);
        }
    }
}

void Board::displayBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (i % 3 == 0 && i != 0) {
            std::cout << "---------------------" << std::endl;
        }
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (j % 3 == 0 && j != 0) {
                std::cout << "| ";
            }
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Board::isValidMove(int row, int col, int num) {
    // Check if placing 'num' at position (row, col) is a valid move

    // Check the row
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Check the column
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // Check the 3x3 subgrid
    int startRow = 3 * (row / 3);
    int startCol = 3 * (col / 3);
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

void Board::placeNumber(int row, int col, int num) {
    // Place 'num' at position (row, col) if the cell is editable
    if (editable[row][col]) {
        grid[row][col] = num;
    }
}

bool Board::isBoardFull() {
    // Check if the Sudoku board is full
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (grid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool Board::isCellEditable(int row, int col) {
    return editable[row][col];
}
