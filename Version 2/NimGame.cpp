#include "NimGame.h"

NimGame::NimGame() {
    this->remCoins = new int[3];
    this->player[0] = new Human();
    this->player[1] = new Computer();
}

void NimGame::run() {
    bool whoseTurn = 0;
    for (int i = 0; i <= 2; ++i) {
        std::cout << "Enter the number of coins in pile number " << i + 1 << ": ";
        std::cin >> this->remCoins[i];
    }
    while (this->remCoins[0] + this->remCoins[1] + this->remCoins[2] > 1){
        if(whoseTurn == 0) separateParagraph("");
        player[whoseTurn]->pickCoins(remCoins);
        std::cout << "> The rest of coins\n";
        for (int i = 0; i <= 2; ++i) {
            std::cout << "Pile number " << i + 1 << " has " << remCoins[i] << " of coins. ";
            if(remCoins[i] == 0) std::cout << "(You cannot pick from this pile anymore)";
            std::cout << '\n';
        }
        std::cout << '\n';
        whoseTurn = !whoseTurn;
    }
    printWinner(whoseTurn);
}

void NimGame::printWinner(bool& whoseTurn) {
    if(whoseTurn == 1){
        std::cout << "The Human player is the winner!\n";
    }else{
        std::cout << "The Computer is the winner!\n";
    }
}

void NimGame::separateParagraph(const std::string &paragraph) {
    int width = 120;
    int part = (width / 2) - (paragraph.size()/2);
    std::cout << std::string(part, '-') << paragraph << std::string(part, '-') << '\n';
}

NimGame::~NimGame() {
    delete [] this->remCoins;
}

