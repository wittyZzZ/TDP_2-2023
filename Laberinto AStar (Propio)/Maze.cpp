#include "Maze.h"

// CONSTRUCTOR
Maze::Maze(int size) {
    this->mazeSize = size;
    this->maze = new int*[size];
    for (int i = 0;i < size;i++) {
        this->maze[i] = new int[size];
        for (int j = 0;j < size;j++) {
            this->maze[i][j] = rand()%100<10?1:0;
        }
    }
    this->op[0] = Operation(HORIZONTAL, 1);
    this->op[1] = Operation(HORIZONTAL, -1);
    this->op[2] = Operation(VERTICAL, 1);
    this->op[3] = Operation(VERTICAL, -1);
}

// DESTRUCTOR
Maze::~Maze() {
    for (int i = 0;i < this->mazeSize;i++) {
        delete[] this->maze[i];
    }
    delete[] this->maze;
}

// MÉTODOS

// print
void Maze::print() {
    for (int i = 0;i < this->mazeSize;i++) {
        for (int j = 0;j < this->mazeSize;j++) {
            std::cout << this->maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// solver (Algoritmo A*)
State* Maze::solver(State* initialS) {
    Stack toVisit(10);
    Stack visited(10);
    toVisit.push(initialS);
    while (!toVisit.isEmpty()) {
        State* actual = toVisit.pop();
        visited.push(actual);
        if (actual->isFinal(this->mazeSize)) {
            return actual;
        }
        for (int i = 0;i < 4;i++) {
            State *newState = this->op[i].operate(actual);
            if(!visited.contains(newState) && !toVisit.contains(newState) 
            & newState->check(this->mazeSize,this->maze)) {
                toVisit.push(newState);
                //std::cout << "PUSHEANDO ESTADO: [" << newState->x << "," << newState->y << "]" <<std::endl;
            }
        }
    }
    return nullptr;
}