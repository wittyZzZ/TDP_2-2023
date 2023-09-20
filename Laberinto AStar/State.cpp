#include "State.h"

State::State(int x, int y, int op, State *parent) {
    this->x = x;
    this->y = y;
    this->op = op;
    this->parent = parent;
}

State::State() {
    // std::cout << "State constructor" << std::endl;
    this->x=-1;
    this->y=-1;
    this->op=-1;
    this->parent=nullptr;
}

State::~State() {
    // std::cout << "State destructor" << std::endl;
}

void State::print() {
    if (this->parent != NULL) {
        this->parent->print();
    }
    switch (this->op) {
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

bool State::isFinal(int size) {
    return(x==size-1 && y==size-1);
}

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