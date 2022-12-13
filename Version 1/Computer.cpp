#include "Computer.h"

void Computer::pickCoins(int* &pilesOfCoins) {
    // first is the number of pile
    // second is the picked amount of coins
    std::pair<int,int> picked = findGoodPile(pilesOfCoins);
    this->coins += picked.second;
    pilesOfCoins[picked.first] -= picked.second;
    printState(picked.first, picked.second);
}

void Computer::printState(int &numberOfPile, int& coinsPicked) {
    std::cout << "Computer picked " << coinsPicked << " from pile " << numberOfPile + 1 << ".\n";
    std::cout << "Computer now has " << this->coins << " of coins.\n";
}

std::pair<int,int> Computer::findGoodPicked(int remCoins) {
    int score = -100000;
    int bestCoinsToTake = -1;
    for (int i = 1; i <= std::min(3, remCoins); ++i) {
        int tmp = isGoodPicked(remCoins - i, false);
        if(tmp > score){
            score = tmp;
            bestCoinsToTake = i;
        }
    }
    return std::make_pair(score, bestCoinsToTake);
}

int Computer::isGoodPicked(int remCoins, bool isMaximizer) {
    if(remCoins == 0){
        if(isMaximizer) return 100;
        else return -100;
    }
    if(isMaximizer){
        int score = -100000;
        for (int i = 1; i <= std::min(3, remCoins); ++i) {
            score = std::max(score ,isGoodPicked(remCoins - i, false));
        }
        return score;
    }else{
        int score = 100000;
        for (int i = 1; i <= std::min(3, remCoins); ++i) {
            score = std::min(score ,isGoodPicked(remCoins - i, true));
        }
        return score;
    }
}

std::pair<int,int> Computer::findGoodPile(int* &remCoins) {
    int pilePicked = -1, bestScore = -100000, coinsPicked = -1;
    for (int i = 0; i <= 2; ++i) {
        if(remCoins[i] == 0) continue;
        std::pair<int,int> goodPicked = findGoodPicked(remCoins[i]);
        if(goodPicked.first > bestScore){
            bestScore = goodPicked.first;
            coinsPicked = goodPicked.second;
            pilePicked = i;
        }
    }
    return std::make_pair(pilePicked, coinsPicked);
}
