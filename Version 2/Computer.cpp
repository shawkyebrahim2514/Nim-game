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

int Computer::findGoodPicked(int* pilesOfCoins, bool isMaximizer) {
    if(pilesOfCoins[0] + pilesOfCoins[1] + pilesOfCoins[2] == 1){
        if(isMaximizer) return -100;
        else return 100;
    }
    if(isMaximizer){
        int bestScore = -100000;
        for (int i = 0; i < 3; ++i) { // loop over all piles
            if(pilesOfCoins[i] == 0) continue;
            for (int takenCoins = 1; takenCoins <= std::min(3, pilesOfCoins[i]); ++takenCoins) {
                pilesOfCoins[i] -= takenCoins;
                bestScore = std::max(bestScore, findGoodPicked(pilesOfCoins, false));
                pilesOfCoins[i] += takenCoins;
            }
        }
        return bestScore;
    }else{
        int bestScore = 100000;
        for (int i = 0; i < 3; ++i) { // loop over all piles
            if(pilesOfCoins[i] == 0) continue;
            for (int takenCoins = 1; takenCoins <= std::min(3, pilesOfCoins[i]); ++takenCoins) {
                pilesOfCoins[i] -= takenCoins;
                bestScore = std::min(bestScore, findGoodPicked(pilesOfCoins, true));
                pilesOfCoins[i] += takenCoins;
            }
        }
        return bestScore;
    }
}

std::pair<int,int> Computer::findGoodPile(int* &pilesOfCoins) {
    int bestTakenPile = -1, bestScore = -100000, bestPickedCoins = -1;
    for (int i = 0; i < 3; ++i) { // loop over all piles
        if(pilesOfCoins[i] == 0) continue;
        for (int takenCoins = 1; takenCoins <= std::min(3, pilesOfCoins[i]); ++takenCoins) {
            pilesOfCoins[i] -= takenCoins;
            int score = findGoodPicked(pilesOfCoins, false);
            pilesOfCoins[i] += takenCoins;
            if(score > bestScore){
                bestScore = score;
                bestTakenPile = i;
                bestPickedCoins = takenCoins;
            }
        }
    }
    return std::make_pair(bestTakenPile, bestPickedCoins);
}