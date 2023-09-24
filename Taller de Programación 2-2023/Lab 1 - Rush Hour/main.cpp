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

/*
   Stack old(1);

   StateRH* s1 = new StateRH();
   s1->setHeurValue(10);
   StateRH* s2 = new StateRH();
   s2->setHeurValue(15);
   StateRH* s3 = new StateRH();
   s3->setHeurValue(25);
   StateRH* s4 = new StateRH();
   s4->setHeurValue(4);
   StateRH* s5 = new StateRH();
   s5->setHeurValue(87);
   StateRH* s6 = new StateRH();
   s6->setHeurValue(44);
   StateRH* s7 = new StateRH();
   s7->setHeurValue(21);
   StateRH* s8 = new StateRH();
   s8->setHeurValue(19);
   StateRH* s9 = new StateRH();
   s9->setHeurValue(57);
   StateRH* s10 = new StateRH();
   s10->setHeurValue(37);

   old.push(s1);
   old.quickSort(old.stack,0,old.size-1);
   old.push(s2);
   old.quickSort(old.stack,0,old.size-1);
   old.push(s3);
   old.push(s4);
   old.push(s5);
   old.push(s6);
   old.quickSort(old.stack,0,old.size-1);
   old.push(s7);
   old.quickSort(old.stack,0,old.size-1);
   old.push(s8);
   old.push(s9);
   old.push(s10);

   old.quickSort(old.stack,0,old.size-1);

   for (int i = 0; i < 10;i++) {
    cout << old.stack[i]->getHeurValue() << endl;
   }
    */
    StateRH* resolution = game->solver(initial);

    if (resolution != nullptr) {
        resolution->printRhBoard();
        resolution->printMoves();
    } else {
        cout << "error" << endl;
    }

    return 0;
}