#include "Car.h"

int main() {

    Car* autoA = new Car(5,2,HORIZONTAL,2,'A');

    // Prueba de impresion de sus posibles movimientos
    int* possibleSteps = autoA->getPossibleSteps();
    for (int i = 0;i < autoA->getStepCount();i++) {
        cout << possibleSteps[i] << endl;
    }

    // Prueba de metodo copyCar()
    Car* autoA2 = autoA->copyCar();

    // Prueba de metodo print()
    autoA->print();
    autoA2->print();
    
    delete autoA;
    delete autoA2;

    return 0;
}