#include "Operation.h"

Operation::Operation(int dir, int step) {
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

void Operation::print() {
    std::cout << "dir: " << this->dir << " step: " << this->step << std::endl;
}

State * Operation::operate(State *s) {
    // new: llama al constructor 
    //      crea espacio en memoria 
    //      retorna un puntero a ese espacio de memoria

    int dx=0,dy=0;
    if (this->dir == HORIZONTAL)
        dy = this->step;
    else if(this->dir == VERTICAL)
        dx = this->step;

    State *newState = new State(s->x+dx,
                                s->y+dy,
                                op[dir][(step+1)/2], 
                                s);


    return newState;
}
