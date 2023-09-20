#ifndef OPERATION_H
#define OPERATION_H


#include <iostream>
#include "State.h"

#define HORIZONTAL 0
#define VERTICAL 1

// (dir,(step+1)/2)
static int op[2][2]={{LEFT,RIGHT},{UP,DOWN}};

class Operation {
public:
    int dir; // HORIZONTAL o VERTICAL
    int step; // +1 o -1
    Operation(int dir, int step);
    Operation();
    ~Operation();
    void print(); // imprime todas las operaciones hasta la raiz
    State *operate(State *s); // podria haber sido x[dir] += step
};

#endif