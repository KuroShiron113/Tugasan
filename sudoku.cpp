#include <iostream>

const int BOARD_SIZE = 3;

class Board {
private:
    int grid[BOARD_SIZE][BOARD_SIZE];

public:
    Board() {
        generateBoard();
    }

    void generateBoard() {

        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                grid[i][j] = 0;
            }
        }
    }

    void displayBoard() {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                std::cout << grid[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool isValidMove(int row, int col, int num) {

        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (grid[row][i] == num || grid[i][col] == num) {
                return false;
            }
        }


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

    void placeNumber(int row, int col, int num) {

        grid[row][col] = num;
    }

    bool isBoardFull() {

        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (grid[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

class Player {
public:
    void makeMove(int &row, int &col, int &num) {
        std::cout << "masukkan baris, kolom, dan angka (1-9): ";
        std::cin >> row >> col >> num;
    }
};

class GameManager {
private:
    Board board;
    Player player;

public:
    void playGame() {
        while (!board.isBoardFull()) {
            board.displayBoard();
            int row, col, num;
            player.makeMove(row, col, num);

            if (row >= 1 && row <= BOARD_SIZE && col >= 1 && col <= BOARD_SIZE &&
                num >= 1 && num <= 9) {
                if (board.isValidMove(row - 1, col - 1, num)) {
                    board.placeNumber(row - 1, col - 1, num);
                    std::cout << "langkah diterima" << std::endl;
                } else {
                    std::cout << "kesalahan, coba lagi!" << std::endl;
                }
            } else {
                std::cout << "kesalahan memasukkan angka, coba lagi!" << std::endl;
            }
        }

        std::cout << "Menang!" << std::endl;
    }
};

int main() {
    GameManager gameManager;
    gameManager.playGame();

    return 0;
}
