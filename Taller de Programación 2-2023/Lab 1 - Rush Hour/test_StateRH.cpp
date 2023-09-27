#include "StateRH.h"

int main() {

    StateRH* s1 = new StateRH();
    StateRH* s2 = new StateRH();
    StateRH* s3 = new StateRH();
    StateRH* s4 = new StateRH();
    StateRH* s5 = new StateRH();

    // Prueba de impresion de tablero de juego vacio
    s1->printRhBoard();
    
    s1->setHeurValue(20);
    s2->setFather(s1);
    s3->setFather(s2);
    s4->setFather(s3);
    s5->setFather(s4);

    s2->setMove("MOVIMIENTO X");
    s3->setMove("MOVIMIENTO Y");
    s4->setMove("MOVIMIENTO Z");
    s5->setMove("MOVIMIENTO W");

    // Prueba de impresion de los movimientos desde el estado raiz al actual
    s5->printMoves();

    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;

    return 0;
}