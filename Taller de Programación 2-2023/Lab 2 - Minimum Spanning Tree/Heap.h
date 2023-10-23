#include <iostream>
#include "Tienda.h"
using namespace std;

class Heap {
    public:
        // Constructor
        Heap(int capacity);
        // Destructor
        ~Heap();
        // Métodos
        void push(Tienda* tienda);
        Tienda *pop();
        bool isEmpty();
        void swap(int i, int j); 
        void bubbleUp(int index); // desde abajo asegura que el padre sea menor que el hijo 
        void heapify(int index); // desde arriba asegura que el padre sea menor que el hijo
        bool contains(Tienda* tienda);
    private:
        // Atributos
        Tienda **heap; // Aqui es doble puntero porque es un arreglo de punteros a Tienda
        int size; // Cuantos hay almacenado aqui
        int capacity; // Cuantos caben aqui
    };