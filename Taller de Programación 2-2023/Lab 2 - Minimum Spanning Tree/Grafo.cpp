#include "Grafo.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ######################################################################### CONSTRUCTOR ###############################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Grafo::Grafo(int nTiendas) {
    this->nTiendas = nTiendas;
    this->heapsAdyacencia = new Heap*[nTiendas];
}

// DESTRUCTOR
Grafo::~Grafo() {
    for (int i = 0;i < this->nTiendas;i++) {
        delete this->heapsAdyacencia[i];
    }
    delete[] this->heapsAdyacencia;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ########################################################################## MÉTODOS ##################################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Getters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
getNTiendas
Descripción: Método que retorna el numero de Tiendas del Grafo
Entrada: void
Salida: Numero de Tiendas (int)
*/
int Grafo::getNTiendas() {
    return this->nTiendas;
}

/*
getHeaps
Descripción: Método que retorna la lista de Heaps del Grafo
Entrada: void
Salida: Heaps (Heap**)
*/
Heap** Grafo::getHeaps() {
    return this->heapsAdyacencia;
}

// Setters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
setNTiendas
Descripción: Método que modifica el numero de Tiendas del Grafo
Entrada: Nuevo numero de Tiendas (int)
Salida: void
*/
void Grafo::setNTiendas(int newNTiendas) {
    this->nTiendas = newNTiendas;
}

/*
setHeaps
Descripción: Método que modifica la lista de Heaps del Grafo
Entrada: Nueva lista de Heaps (Heap**)
Salida: void
*/
void Grafo::setHeaps(Heap** newHeaps) {
    this->heapsAdyacencia = newHeaps;
}

// OTROS MÉTODOS
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
