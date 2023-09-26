#include <iostream>

using namespace std;

class State {
    public:
    int value; // este es el valor que define la heuristica de como seleccionar el nodo (menor valor)
    State *parent;
    State(int value, State *parent);
    State();
    ~State();
    void print();
};