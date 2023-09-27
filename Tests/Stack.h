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
        bool isEmpty();
        void push(StateRH* state);
        StateRH* pop();
        bool contains(StateRH* state);
        int partition(StateRH **stack,int start,int end);
        void quickSort(StateRH **stack, int start, int end);
};