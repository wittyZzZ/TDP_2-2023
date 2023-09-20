#include "Stack.h"
// Aqui vamos a implementar todos los metodos
// Constructor
Stack::Stack(int size) { // Dentro del domino de nombres "Stack" definimos el metodo "Stack"
    // this->  se refiere al objeto actual
    this->size = size;
    this->stack = new State*[size];
    this->top = -1; // si esta vacio decimos que el top es -1
}

// Destructor
Stack::~Stack() {
    delete[] this->stack; // liberamos cada elemento del arreglo
}

void Stack::push(State *value) {
    if (this->top == this->size - 1) { // si ya no queda mas memoria entonces duplicamos
        State **newState = new State*[this->size * 2];
        for (int i = 0; i < this->size; i++) {
            newState[i] = this->stack[i];
        }
        delete[] this->stack;
        this->stack = newState;
        this->size *= 2;
    }    
    this->top++;
    this->stack[this->top] = value;
}

State* Stack::pop() {
    if (this->isEmpty()) {
        throw "Stack is empty";
    }
    State *value = this->stack[this->top];
    this->top--;
    return value;
}

bool Stack::isEmpty() {
    return this->top == -1;
}

void Stack::print() {
    std::cout << "[";
    for (int i = 0; i < this->top; i++) {
        std::cout << this->stack[i]->x << "-" << this->stack[i]->y << ", ";
    }
    if (this->top != -1) {
        std::cout << this->stack[top]->x << "-" << this->stack[top]->y ;
    }
    std::cout << "]" << std::endl;
}

bool Stack::contains(State *value) {
    for (int i = 0; i <= this->top; i++) {
        if (this->stack[i]->x == value->x && this->stack[i]->y == value->y) {
            return true;
        }
    }
    return false;
}