#include <iostream>
#include "Stack.h"
#include "Operation.h"

class Maze {
    public:
        // Constructor
        Maze(int size); 
        // Destructor
        ~Maze(); 

        // Atributos
        int mazeSize;
        int **maze;
        Operation op[4];

        // Métodos
        void print();
        State* solver(State* initialS);
};