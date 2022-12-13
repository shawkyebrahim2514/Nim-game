#ifndef NIM_GAME_COMPUTER_H
#define NIM_GAME_COMPUTER_H
#include "Player.h"

class Computer : public Player{
private:
    int findGoodPicked(int* pilesOfCoins, bool isMaximizer);
    void printState(int& pickedCoins, int& numberOfPile) override;
    std::pair<int,int> findGoodPile(int*& pilesOfCoins);
public:
    void pickCoins(int*& pilesOfCoins) override;
    bool isWinner(){};
};

#endif