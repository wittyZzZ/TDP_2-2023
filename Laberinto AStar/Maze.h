#include <iostream>
#include "Stack.h"
#include "Operation.h"
//class Operation;
using namespace std;

class Maze {
    public:
        Maze(int size);
        ~Maze();
        State *solve(State *initialState); // algorithmo A*
        void print();
    private:
        Operation op[4];
        int mazeSize;
        int **maze;
};