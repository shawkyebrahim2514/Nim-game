#ifndef NIM_GAME_COMPUTER_H
#define NIM_GAME_COMPUTER_H
#include "Player.h"

class Computer : public Player{
private:
    std::pair<int,int> findGoodPicked(int remCoins);
    int isGoodPicked(int remCoins, bool isMaximizer);
    void printState(int& pickedCoins, int& numberOfPile) override;
    std::pair<int,int> findGoodPile(int*& remCoins);
public:
    void pickCoins(int*& pilesOfCoins) override;
    bool isWinner(){};
};


#endif