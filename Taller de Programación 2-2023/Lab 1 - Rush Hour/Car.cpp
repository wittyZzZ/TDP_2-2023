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
        this->possibleSteps = new int[6]{-3,-2,-1,1,2,3};
    } else {
        this->stepCount = 8;
        this->possibleSteps = new int[8]{-4,-3,-2,-1,1,2,3,4};
    }
}

// DESTRUCTOR
Car::~Car() {
    delete[] this->possibleSteps;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ########################################################################## MÉTODOS ##################################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Getters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
getDir
Descripción: Método que retorna el valor de dirección del Car
Entrada: void
Salida: El valor de dirección (int)
*/
int Car::getDir() {
    return this->dir;
}

/*
getLargo
Descripción: Método que retorna el largo del Car
Entrada: void
Salida: El largo (int)
*/      
int Car::getLargo() {
    return this->largo;
}

/*
getX
Descripción: Método que retorna la coordenada X del Car
Entrada: void
Salida: La coordenada X (int)
*/
int Car::getX() {
    return this->x;
}

/*
getY
Descripción: Método que retorna la coordenada Y del Car
Entrada: void
Salida: La coordenada Y (int)
*/
int Car::getY() {
    return this->y;
}

/*
getSymbol
Descripción: Método que retorna el simbolo del Car
Entrada: void
Salida: El simbolo (char)
*/
char Car::getSymbol() {
    return this->symbol;
}

/*
getPossibleSteps
Descripción: Método que retorna los posibles valores de movimiento del Car
Entrada: void
Salida: Los valores de movimiento (int*)
*/
int* Car::getPossibleSteps() {
    return this->possibleSteps;
}

/*
getStepCount
Descripción: Método que retorna la cantidad de movimientos del Car
Entrada: void
Salida: La cantidad de movimientos (int)
*/
int Car::getStepCount() {
    return this->stepCount;
}

// Setters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
setX
Descripción: Método que modifica la coordenada X del Car
Entrada: La nueva coordenada X (int)
Salida: void
*/
void Car::setX(int x) {
    this->x = x;
}

/*
setY
Descripción: Método que modifica la coordenada Y del Car
Entrada: La nueva coordenada Y (int)
Salida: void
*/
void Car::setY(int y) {
    this->y = y;
}

// OTROS MÉTODOS
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
print
Descripción: Método que imprime los datos del Car
Entrada: void
Salida: void
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
copyCar
Descripción: Método que copia los datos del Car generando otro igual
Entrada: void
Salida: El Car copia (Car*)
*/
Car* Car::copyCar() {
    Car* newCar = new Car(this->x,this->y,this->dir,this->largo,this->symbol);
    return newCar;
}