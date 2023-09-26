#include "Heap.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ######################################################################### CONSTRUCTOR ###############################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Heap::Heap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->heap = new StateRH*[capacity];
}

// Destructor
Heap::~Heap() {
    /*
    for (int i=0; i < this->size; i++) {
        delete this->heap[i];
    }
    */
    delete[] this->heap;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ########################################################################## MÉTODOS ##################################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
isEmpty
Descripción: Método que verifica si el Stack esta vacío o no
Entrada: void
Salida: Resultado de si esta vacío o no (bool)
*/
bool Heap::isEmpty() {
    return this->size == 0;
}

/*
Swap
Descripción: Método que intercambia la posición de dos elementos del heap
Entrada: Las posiciones a intercambiarse (int X int)
Salida: void
*/
void Heap::swap(int i, int j) {
    StateRH* temp = this->heap[i];
    this->heap[i] = this->heap[j];
    this->heap[j] = temp;
}

/*
Heapify
Descripción: Método que desde arriba asegura que el padre sea menor que el hijo dentro del Heap
Entrada: La posición del Heap desde donde empieza a trabajar (int)
Salida: void
*/
void Heap::heapify(int index) {
    int left = 2*index+1;
    int right = 2*index+2;
    int smallest = index;
    if (left < this->size && this->heap[left]->getHeurValue() < this->heap[smallest]->getHeurValue()) {
        smallest = left;
    }
    if (right < this->size && this->heap[right]->getHeurValue() < this->heap[smallest]->getHeurValue()) {
        smallest = right;
    }
    if (smallest != index) {
        this->swap(index, smallest); // smallest va ser el hijo menor de ambos
        this->heapify(smallest);
    }
}

/*
bubbleUp
Descripción: Método que desde abajo asegura que el padre sea menor que el hijo dentro del Heap
Entrada: La posición del Heap desde donde empieza a trabajar (int)
Salida: void
*/
void Heap::bubbleUp(int index) {
    int parent = (index-1)/2;
    if (parent >= 0 && this->heap[index]->getHeurValue() < this->heap[parent]->getHeurValue()) {
        this->swap(index, parent); // caso que no se cumple padre < hijo
        this->bubbleUp(parent);
    }
}

/*
Pop
Descripción: Método que expulsa un Estado del Heap
Entrada: void
Salida: El estado expulsado (StateRH*)
*/
StateRH* Heap::pop() {
    if (isEmpty()) { // Ojo retorna nulo si esta vacio
        return nullptr;
    }
    StateRH* state = this->heap[0]; // tomo la raiz
    this->heap[0] = this->heap[this->size-1]; // pongo el ultimo en la raiz
    this->size--; // reduzco el size
    this->heapify(0); // burbujea hacia abajo intercambiando con el menor de los hijos
    return state;
}

/*
Push
Descripción: Método que agrega un Estado al Heap
Entrada: El estado a agregar (StateRH*)
Salida: void
*/
void Heap::push(StateRH* state) {
    if (this->size == this->capacity) {
        StateRH** temp = new StateRH*[this->capacity + 1];
        for (int i=0; i < this->size; i++) {
            temp[i] = this->heap[i];
        }
        delete[] this->heap;
        this->heap = temp;
        this->capacity++;
    }
    this->heap[this->size] = state; // lo pongo al final
    this->bubbleUp(this->size); // burbujea hacia arriba intercambiando con el padre
    this->size++; // aumento el size
}

/*
Contains
Descripción: Método que verifica si un Estado ya esta dentro del Stack
Entrada: El Estado a revisar (StateRH*)
Salida: Resultado de si esta contenido o no (bool)
*/
bool Heap::contains(StateRH* state) {
    for (int i = 0;i < this->size;i++) {
        char** sBoard = heap[i]->getBoard();
        if (state->isEqualBoard(sBoard)) {
            return true;
        } 
    }
    return false;
}
