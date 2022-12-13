#ifndef NIM_GAME_PLAYER_H
#define NIM_GAME_PLAYER_H
#include <iostream>

class Player {
protected:
    int coins;
    virtual void printState(int& pickedCoins, int& numberOfPile) = 0;
public:
    Player(){coins = 0;}
    virtual void pickCoins(int*& nCoins) = 0;
    virtual bool isWinner() = 0;
};


#endif
