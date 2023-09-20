#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include "State.h"

#define HORIZONTAL 0
#define VERTICAL 1

class Operation{
    public:
        // Contructor
        Operation(int dir,int step);
        Operation();
        // Destructor
        ~Operation();

        // Atributos
        int dir;
        int step;
        int op[2][2] = {{LEFT,RIGHT},{UP,DOWN}};

        // Métodos
        State* operate(State* s);
};

#endif