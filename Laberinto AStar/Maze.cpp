#include "Maze.h"

Maze::Maze(int size) {

    this->mazeSize = size;
    this->maze = new int*[size];
    for (int i = 0; i < size; i++) {
        this->maze[i] = new int[size];
        for (int j = 0; j < size; j++) {
            this->maze[i][j] = rand()%100<10?1:0;
        }
    }

    // creamos las operaciones
    this->op[0] = Operation(HORIZONTAL, 1);
    this->op[1] = Operation(HORIZONTAL, -1);
    this->op[2] = Operation(VERTICAL, 1);
    this->op[3] = Operation(VERTICAL, -1);

}

Maze::~Maze() {
    for (int i = 0; i < this->mazeSize; i++) {
        delete[] this->maze[i];
    }
    delete[] this->maze;
}

// A* algorithm
State* Maze::solve(State *initialState) {
    Stack open(10);
    Stack closed(10);
    open.push(initialState);
    while (!open.isEmpty()) {
        State *e = open.pop();
        closed.push(e);
        if (e->isFinal(this->mazeSize)) {
            return(e);
        }
        for (int i=0; i<4; i++) {
            State *newState = this->op[i].operate(e);
            if (!closed.contains(newState) && 
                !open.contains(newState) && 
                newState->check(this->mazeSize, this->maze)) {
                open.push(newState);
                cout << "Pushing: "<<newState->x<<","<<newState->y<<endl;
                
            }
        }
    }
    return nullptr;
}

void Maze::print() {
    for (int i=0; i<this->mazeSize; i++) {
        for (int j=0; j<this->mazeSize; j++) {
            std::cout << this->maze[i][j] << " ";
        }
        std::cout << std::endl;
    }

}
