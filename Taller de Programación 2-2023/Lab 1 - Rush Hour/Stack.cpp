#include "Stack.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ######################################################################### CONSTRUCTOR ###############################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Stack::Stack(int size) {
    this->size = size;
    this->top = -1;
    this->stack = new StateRH*[size];
}

// DESTRUCTOR
Stack::~Stack() {
    delete[] this->stack;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ########################################################################## MÉTODOS ##################################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

// isEmpty
bool Stack::isEmpty() {
    return this->top == -1;
}

// PUSH
void Stack::push(StateRH* state) {
    if (this->top == this->size - 1) {
        StateRH** newStack = new StateRH*[this->size * 2];
        for (int i = 0;i < this->size;i++) {
            newStack[i] = this->stack[i];
        }
        delete[] this->stack;
        this->stack = newStack;
        this->size *= 2;
    }
    this->top++;
    this->stack[this->top] = state;
}

// POP
StateRH* Stack::pop() {
    if (this->isEmpty()) {
        throw "El Stack esta vacio";
    } else {
        StateRH* state = this->stack[this->top];
        this->top--;
        return state;
    }
}

// PRINT
void Stack::print() {
    std::cout <<  "LOS OLD DEL PRINT:" << std::endl;
}


// CONTAINS
bool Stack::contains(StateRH* state) {
    for (int i = 0;i < this->top+1;i++) {
        char** sBoard = stack[i]->getBoard();
        if (state->isEqualBoard(sBoard)) {
            return true;
        } 
    }
    return false;
}

