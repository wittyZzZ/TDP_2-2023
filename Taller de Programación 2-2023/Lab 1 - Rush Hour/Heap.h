#include <iostream>
#include "StateRH.h"
using namespace std;

class Heap {
    public:
    // Constructor
    Heap(int capacity);
    // Destructor
    ~Heap();
    // Atributos
    StateRH **heap; // Aqui es doble puntero porque es un arreglo de punteros a State
    int size; // Cuantos hay almacenado aqui
    int capacity; // Cuantos caben aqui
    // Métodos
    void push(StateRH* state);
    StateRH *pop();
    bool isEmpty();
    void swap(int i, int j); 
    void bubbleUp(int index); // desde abajo asegura que el padre sea menor que el hijo 
    void heapify(int index); // desde arriba asegura que el padre sea menor que el hijo
    bool contains(StateRH* state);
};