#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "board.h"
#include "player.h"

class GameManager {
private:
    Board board;
    Player player;

public:
    void playGame();
};

#endif
