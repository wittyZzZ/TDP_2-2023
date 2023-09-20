#include "State.h"

// CONSTRUCTOR
State::State(int x,int y,int op,State *padre) {
    this->x = x;
    this->y = y;
    this->op = op;
    this->padre = padre;
}

State::State() {
    this->x = -1;
    this->y = -1;
    this->op = -1;
    this->padre = nullptr;
}

// DESTRUCTOR
State::~State() {
}

// MÉTODOS
void State::print() {
    // RECURSIVO
    if (this->padre != NULL) {
        this->padre->print();
    }
    switch (this->op)
    {
    case UP:
        std::cout << "UP" << std::endl;
        break;
    case DOWN:
        std::cout << "DOWN" << std::endl;
        break;
    case LEFT:
        std::cout << "LEFT" << std::endl;
        break;
    case RIGHT:
        std::cout << "RIGHT" << std::endl;
        break;
    }
}

bool State::isFinal(int mazeSize) {
    return (this->x == mazeSize-1 && this->y == mazeSize-1);
}

/*
DESCRIPCIÓN: Checkea si el estado es válido dentro de la matriz (comprueba si se sale de los límites)
ENTRADA: (int) Tamaño del Laberinto, (int**) El laberinto
SALIDA: (bool) TRUE o FALSE
*/
bool State::check(int mazeSize, int **maze) {
    if (this->x < 0 || this->x >= mazeSize) {
        return false;
    }
    if (this->y < 0 || this->y >= mazeSize) {
        return false;
    }
    if (maze[this->x][this->y] == 1) {
        return false;
    }
    return true;
}

