#include "Human.h"

void Human::pickCoins(int*& remCoins) {
    int pickedCoins, numberOfPile;
    while (true){
        std::cout << "Enter the number of pile to pick from: ";
        std::cin >> numberOfPile;
        while (numberOfPile < 1 || numberOfPile > 3 || remCoins[numberOfPile - 1] == 0){
            std::cout << "Enter correct number of pile which has coins: ";
            std::cin >> numberOfPile;
        }
        std::cout << "The pile number " << numberOfPile << " has " << remCoins[numberOfPile - 1] << " coins.\n";
        std::cout << "Enter the amount of coins from 1 to " << std::max(1, std::min(3,remCoins[numberOfPile - 1]))
                    << " to pick from pile " << numberOfPile << ": ";
        std::cin >> pickedCoins;
        if(pickedCoins >= 1 && pickedCoins <= std::min(3, remCoins[numberOfPile - 1])) break;
    }
    this->coins += pickedCoins;
    remCoins[numberOfPile - 1] -= pickedCoins;
    printState(pickedCoins, numberOfPile);
}

void Human::printState(int &pickedCoins, int& numberOfPile) {
    std::cout << "Human player picked " << pickedCoins << " from pile " << numberOfPile << ".\n";
    std::cout << "Human player now has " << this->coins << " of coins.\n";
}

bool Human::isWinner() {
    return this->coins%2 == 0;
}