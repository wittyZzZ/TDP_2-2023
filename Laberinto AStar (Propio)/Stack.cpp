#include "Stack.h"

// CONSTRUCTOR
Stack::Stack(int size) {
    this->size = size;
    this->top = -1;
    this->stack = new State*[size];
}

// DESTRUCTOR
Stack::~Stack() {
    delete[] this->stack;
}

// MÉTODOS

// isEmpty
bool Stack::isEmpty() {
    return this->top == -1;
}

// PUSH
void Stack::push(State* state) {
    if (this->top == this->size - 1) {
        State **newStack = new State*[this->size * 2];
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
State* Stack::pop() {
    if (this->isEmpty()) {
        throw "El Stack esta vacio";
    } else {
        State* state = this->stack[this->top];
        this->top--;
        return state;
    }
}

// PRINT
void Stack::print() {
    std::cout <<  "LOS OLD DEL PRINT:" << std::endl;
}

// CONTAINS
bool Stack::contains(State* state) {
    for (int i = 0;i <= this->top;i++) {
        if (this->stack[i]->x == state->x && this->stack[i]->y == state->y) {
            return true;
        }
    }
    return false;
}

