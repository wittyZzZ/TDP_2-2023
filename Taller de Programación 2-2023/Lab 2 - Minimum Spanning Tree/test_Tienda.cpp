#include "Tienda.h"

int main() {

    // Se crea una Tienda con ID = 0 y Costo = 20
    Tienda* tienda = new Tienda(0,20);

    // Se cambia el ID a 1
    tienda->setId(1);

    // Se cambia el Costo a 9
    tienda->setCosto(9);

    // Se imprime la Tienda
    tienda->printTienda();

    delete tienda;

    return 0;
}