#include <iostream>
//#include "Stack.h"
#include "Heap.h"
#include <fstream> // para trabajar con archivos
#include <string> // para tener objetos de arreglos de char de largo autoincrementable
#include <sstream> // para trabajar con streams de strings
using namespace std;

class RHGame {
    public:
        // Constructor
        RHGame();
        // Destructor
        ~RHGame();
        // Métodos
        // Getters
        int getCarsCount();
        int getWallsCount();
        char** getBoard();
        // Setters
        void setCarsCount(int carsCount);
        void setWallsCount(int wallsCount);
        void setBoard(char** board);
        // Otros Métodos
        void readFile(string carsFile,string wallsFile,StateRH* initial);
        void printBoard();
        void makeRhBoard(StateRH* s);
        StateRH* operate(StateRH* s,int carPos,int stepPos);
        StateRH* operate2(StateRH* s,int carPos,int steps);
        StateRH* solver(StateRH* initial);
    private:
        // Atributos
        int carsCount;
        int wallsCount;
        char** board;
};