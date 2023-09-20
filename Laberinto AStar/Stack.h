#include <iostream>
#include "State.h"
// declaracion abstracta de la clase Stack
class Stack {
    public: // todo aquello que el usuario puede llamar
        Stack(int size); // Constructor
        ~Stack(); // Destructor
        void push(State *value);
        State* pop();
        bool isEmpty();
        void print();
        bool contains(State *value);
//    private: // aquello que esta escondido para el usuario
        State **stack; // Pointer to the array that will store the stack
        int top;
        int size;
};