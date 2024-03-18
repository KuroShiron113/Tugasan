#include "game_manager.h"

void GameManager::playGame() {
    while (!board.isBoardFull()) {
        // Menampilkan papan
        board.displayBoard();

        // Meminta pemain untuk memasukkan langkah
        int row, col, num;
        player.makeMove(row, col, num);

        // Memeriksa apakah langkah yang dimasukkan valid
        if (row >= 1 && row <= BOARD_SIZE && col >= 1 && col <= BOARD_SIZE &&
            num >= 1 && num <= 9) {
            // Mengonversi input pemain ke indeks array (indeks dimulai dari 0)
            int rowIndex = row - 1;
            int colIndex = col - 1;

            // Memeriksa apakah langkah yang dimasukkan valid dan sel dapat diubah
            if (board.isValidMove(rowIndex, colIndex, num) && board.isCellEditable(rowIndex, colIndex)) {
                // Menempatkan angka ke dalam sel jika langkah valid
                board.placeNumber(rowIndex, colIndex, num);
                std::cout << "Move accepted." << std::endl;
            } else {
                // Menampilkan pesan jika langkah tidak valid atau sel tidak dapat diubah
                std::cout << "Invalid move or cell cannot be changed. Try again!" << std::endl;
            }
        } else {
            // Menampilkan pesan jika input pemain tidak valid
            std::cout << "Invalid input. Try again!" << std::endl;
        }
    }

    // Menampilkan pesan kemenangan jika papan penuh
    std::cout << "You win!" << std::endl;
}
