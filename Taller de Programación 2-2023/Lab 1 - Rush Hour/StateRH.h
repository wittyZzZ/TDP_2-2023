#include <iostream>
#include "Car.h"
#include <string>
using namespace std;

class StateRH {
    public:
        // Constructor
        StateRH();
        // Destructor
        ~StateRH();
        // Métodos
        // Getters
        int getHeurValue();
        Car** getCars();
        int getCarsCount();
        char getRedCarSymbol();
        string getMove();
        StateRH* getFather();
        char** getBoard();
        // Setters
        void setHeurValue(int heurValue);
        void setCarsCount(int carsCount);
        void setCars(Car** cars);
        void setRedCarSymbol(char symbol);
        void setRhBoard(char** rhBoard);
        void setMove(string move);
        void setFather(StateRH* father);
        // Otros Métodos
        void printRhBoard();
        void printMoves();
        StateRH* copyState();
        bool isSolved();
        bool isEqualBoard(char** board);
        int makeHeurValue();
    private:
        // Atributos
        int heurValue;
        int carsCount;
        char redCarSymbol;
        string move;
        Car** cars;
        char** rhBoard;
        StateRH* father;
};