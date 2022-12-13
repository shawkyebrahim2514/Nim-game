#ifndef NIM_GAME_NIMGAME_H
#define NIM_GAME_NIMGAME_H
#include "Player.h"
#include "Human.h"
#include "Computer.h"

class NimGame {
private:
    int* remCoins;
    Player* player[2]; // 0 for the Human, 1 for the computer
    void printWinner(bool& whoseTurn);
    void separateParagraph(const std::string& paragraph);
public:
    NimGame();
    void run();
    ~NimGame();
};

#endif