#include <iostream>
#include "State.h"

class Stack {
    public:
        // Constructor
        Stack(int size); 
        // Destructor
        ~Stack(); 

        // Atributos
        int size;
        int top;
        State **stack;

        // Métodos
        bool isEmpty();
        void push(State* state);
        State* pop();
        void print();
        bool contains(State* state);
};