#include <iostream>
using namespace std;

#define HORIZONTAL 0
#define VERTICAL 1

class Car {
    public:
        // Constructor
        Car(int x,int y,int dir,int largo,char symbol);
        // Destructor
        ~Car();
        // Métodos
        // Getters
        int getDir();
        int getLargo();
        int getX();
        int getY();
        char getSymbol();
        int* getPossibleSteps();
        int getStepCount();
        // Setters
        void setX(int x);
        void setY(int y);
        // Otros Métodos
        void print();
        Car* copyCar();
    private:
        // Atributos
        int x;
        int y;
        int dir;
        int largo;
        char symbol;
        int *possibleSteps;
        int stepCount;
};