#include <iostream>
#include "Maze.h"

int main() {

    Maze maze(10);
    maze.print();

    State* initial = new State(0,0,UP,nullptr);

    State* solution = maze.solver(initial);

    if (solution != nullptr) {
        solution->print();
    } else {
        std::cout<<"No solution found"<<std::endl;
    }

    return 0;
}

