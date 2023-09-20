#include "Car.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ######################################################################### CONSTRUCTOR ###############################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Car::Car(int x,int y,int dir,int largo,char symbol) {
    this->x = x;
    this->y = y;
    this->dir = dir;
    this->largo = largo;
    this->symbol = symbol;
    if (largo == 3) {
        this->stepCount = 6;
        this->possibleSteps = new int[6];
        int j = -3;
        for (int i = 0;i < 6;i++) {
            if (j == 0) {j++;}
            this->possibleSteps[i] = j;
            j++;
        }
    } else {
        this->stepCount = 8;
        this->possibleSteps = new int[8];
        int j = -4;
        for (int i = 0;i < 8;i++) {
            if (j == 0) {j++;}
            this->possibleSteps[i] = j;
            j++;
        }
    }
}

// DESTRUCTOR
Car::~Car() {}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ########################################################################## MÉTODOS ##################################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Getters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

int Car::getDir() {
    return this->dir;
}
          
int Car::getLargo() {
    return this->largo;
}

int Car::getX() {
    return this->x;
}

int Car::getY() {
    return this->y;
}

char Car::getSymbol() {
    return this->symbol;
}

int* Car::getPossibleSteps() {
    return this->possibleSteps;
}

int Car::getStepCount() {
    return this->stepCount;
}

// Setters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Car::setX(int x) {
    this->x = x;
}
void Car::setY(int y) {
    this->y = y;
}

// OTROS MÉTODOS
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
Entrada:
Salida:
Descripción: 
*/
void Car::print() {
    if (this->dir == 0) {
        std::cout << "Auto " << this->symbol <<": [" << this->x << "," << this->y << "] ; HORIZONTAL ; Largo: " << this->largo << " ; ";
        if (this->largo == 3) {
            for (int i = 0;i < 6;i++) {
                std::cout << this->possibleSteps[i] << " - ";
            }
        } else {
            for (int i = 0;i < 8;i++) {
                std::cout << this->possibleSteps[i] << " - ";
            }
        }
    } else {
        std::cout << "Auto " << this->symbol <<": [" << this->x << "," << this->y << "] ; VERTICAL ; Largo: " << this->largo << " ; ";
        if (this->largo == 3) {
            for (int i = 0;i < 6;i++) {
                std::cout << this->possibleSteps[i] << " - ";
            }
        } else {
            for (int i = 0;i < 8;i++) {
                std::cout << this->possibleSteps[i] << " - ";
            }
        }
    } 
}

/*
Entrada:
Salida:
Descripción: 
*/
Car* Car::copyCar() {
    Car* newCar = new Car(this->x,this->y,this->dir,this->largo,this->symbol);
    return newCar;
}