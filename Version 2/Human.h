#ifndef NIM_GAME_HUMAN_H
#define NIM_GAME_HUMAN_H
#include "Player.h"

class Human : public Player{
private:
    void printState(int& pickedCoins, int& numberOfPile) override;
public:
    void pickCoins(int*& remCoins) override;
    bool isWinner() override;
};

#endif