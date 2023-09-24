#include <iostream>
#include "RHGame.h"
using namespace std;

int main() {

    RHGame* game = new RHGame();
    StateRH* initial = new StateRH();

    game->readFile("game1.txt","walls1.txt",initial);

    Car** car = initial->getCars();
    for (int i = 0; i < game->getCarsCount();i++) {
        std::cout << i << " ";
        car[i]->print();
        std::cout << std::endl;
    }

    game->printBoard();
    initial->printRhBoard();

    StateRH* resolution = game->solver(initial);

    if (resolution != nullptr) {
        resolution->printRhBoard();
        resolution->printMoves();
    } else {
        cout << "error" << endl;
    }

    return 0;
}