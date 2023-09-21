#include <iostream>
#include "StateRH.h"

class Stack {
    public:
        // Constructor
        Stack(int size); 
        // Destructor
        ~Stack(); 
        // Atributos
        int size;
        int top;
        StateRH **stack;
        // Métodos
        int partition(StateRH **stack,int start,int end);
        void quickSort(StateRH **stack, int start, int end);
        bool isEmpty();
        void push(StateRH* state);
        StateRH* pop();
        void print();
        bool contains(StateRH* state);
};