#include "Heap.h"

Heap::Heap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->heap = new State*[capacity];
}

Heap::~Heap() {
    for (int i=0; i<this->size; i++) {
        delete this->heap[i];
    }
    delete[] this->heap;
}

void Heap::swap(int i, int j) {
    State *temp = this->heap[i];
    this->heap[i] = this->heap[j];
    this->heap[j] = temp;
}

State * Heap::pop() {
    if (isEmpty()) { // Ojo retorna nulo si esta vacio
        return nullptr;
    }
    State *state = this->heap[0]; // tomo la raiz
    this->heap[0] = this->heap[this->size-1]; // pongo el ultimo en la raiz
    this->size--; // reduzco el size
    this->heapify(0); // burbujea hacia abajo intercambiando con el menor de los hijos
    return state;
}

void Heap::heapify(int index) {
    int left = 2*index+1;
    int right = 2*index+2;
    int smallest = index;
    if (left < this->size && this->heap[left]->value < this->heap[smallest]->value) {
        smallest = left;
    }
    if (right < this->size && this->heap[right]->value < this->heap[smallest]->value) {
        smallest = right;
    }
    if (smallest != index) {
        this->swap(index, smallest); // smallest va ser el hijo menor de ambos
        this->heapify(smallest);
    }
}

void Heap::push(State *state) {
    if (this->size == this->capacity) {
        State **temp = new State*[this->capacity + 1];
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

void Heap::bubbleUp(int index) {
    int parent = (index-1)/2;
    if (parent >= 0 && this->heap[index]->value < this->heap[parent]->value) {
        this->swap(index, parent); // caso que no se cumple padre < hijo
        this->bubbleUp(parent);
    }
}

bool Heap::isEmpty() {
    return this->size == 0;
}   
