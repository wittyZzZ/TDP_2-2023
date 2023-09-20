#ifndef STATE_H
#define STATE_H
#include <iostream>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

class State{
    public:
        // Constructor
        State(int x,int y,int op,State *padre);
        State();
        // Destructor
        ~State();

        // Atributos
        int x;
        int y; 
        int op; // Operacion que se hizo para llegar al estado
        State *padre; // Nulo en estado inicial

        // Métodos
        void print();
        bool isFinal(int mazeSize);
        bool check(int mazeSize,int **maze);
};
#endif