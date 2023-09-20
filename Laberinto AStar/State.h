#ifndef STATE_H
#define STATE_H
#include <iostream>

// las operaciones
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

class State{
    public:
        State(int x, int y, int op, State *parent);
        State();
        ~State();
        void print(); // imprime todas las operaciones hasta la raiz
        bool isFinal(int size);
        bool check(int mazeSize, int **maze);
//    private:
        int x; // fila
        int y; // columna
        int op; // operacion UP, DOWN ,...
        State *parent; // es nulo si es estado inicial
};
#endif