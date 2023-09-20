#include "Operation.h"

// CONSTRUCTOR
Operation::Operation(int dir,int step) {
    this->dir = dir;
    this->step = step;
}

Operation::Operation() {
    this->dir = -1;
    this->step = -1;
}

Operation::~Operation() {
    // std::cout << "Operation destructor" << std::endl;
}

/*
DESCRIPCIÓN: Realiza la operación en un State
*/

State* Operation::operate(State* s) {
    int d1 = 0,d2 = 0; // maze[d1][d2] => d2 = HORIZONTAL && d1 = VERTICAL
    if (this->dir == HORIZONTAL) {
        d2 = this->step;
    } else if (this->dir == VERTICAL) {
        d1 = this->step;
    }
    State* newState = new State(s->x+d1,s->y+d2,this->op[this->dir][(this->step+1)/2],s);

    return newState;
}