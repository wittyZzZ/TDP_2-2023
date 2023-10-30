#include "Heap.h"

int main() {

    // Se crea un Heap con capacidad 10
    Heap* heap = new Heap(10);

    // Se crean varias Tiendas
    Tienda* t1 = new Tienda(1,4);
    Tienda* t2 = new Tienda(2,3);
    Tienda* t3 = new Tienda(3,2);
    Tienda* t4 = new Tienda(5,5);
    Tienda* t5 = new Tienda(5,9);
    Tienda* t6 = new Tienda(6,7);

    // Se almacenan las Tiendas en el Heap
    heap->push(t1);
    heap->push(t2);
    heap->push(t3);
    heap->push(t4);
    heap->push(t5);
    heap->push(t6);

    // Se saca una Tienda del Heap, la cual deberia poseer el menor Costo, es decir, la Tienda con ID = 3
    Tienda* t = heap->pop();

    // Se imprime Tienda
    t->printTienda();

    delete heap;

    return 0;
}