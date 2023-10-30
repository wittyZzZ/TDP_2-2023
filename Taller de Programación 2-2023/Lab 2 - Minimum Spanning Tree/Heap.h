#ifndef Heap_h
#define Heap_h

#include <iostream>
#include "Tienda.h"

using namespace std;

/*
    > Clase Heap:

    Esta clase se usa para poder almacenar Tiendas, de manera que la Tienda que posea
    el menor valor de costo sea la primera en ser sacada.

    Esta clase es representada por: Tamaño (int) X Capacidad (int) X Arreglo de punteros a Tienda (Tienda**)
    
*/

class Heap {
    private:
        // Atributos
        Tienda **heap; // Aqui es doble puntero porque es un arreglo de punteros a Tienda
        int size; // Cuantos hay almacenado aqui
        int capacity; // Cuantos caben aqui
    public:
        // Constructor
        Heap(int capacity);
        // Destructor
        ~Heap();
        // Métodos
        void push(Tienda* tienda);
        Tienda *pop();
        void pop2();
        bool isEmpty();
        void swap(int i, int j); 
        void bubbleUp(int index); // desde abajo asegura que el padre sea menor que el hijo 
        void heapify(int index); // desde arriba asegura que el padre sea menor que el hijo
        bool contains(Tienda* tienda);
        void printHeap();
};

#endif