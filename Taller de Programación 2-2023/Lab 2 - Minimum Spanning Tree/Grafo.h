#ifndef Grafo_h
#define Grafo_h

#include <iostream>
#include <fstream> 
#include <string> 
#include <sstream> 
#include "Heap.h"

using namespace std;

/*
    > Clase Grafo:

    Esta clase se usa para modelar el como se relacionan distintas tiendas según sus distancias con unas u otras.
    Se usa una variación de la representación llamada "Listas de Adyacencia", pero en este caso usan "Heaps de Adyacencia".
    A cada Tienda le corresponde un Heap que contendrá a las Tiendas con quien se relaciona.

    Esta clase se representa por: Número de tiendas (int) X Arreglo de punteros a Heap (Heap**)

*/

class Grafo {
    private:
        // Atributos
        int nTiendas;
        Heap **heapsAdyacencia;   
    public:
        // Constructor
        Grafo();
        Grafo(int nTiendas);
        // Destructor
        ~Grafo();
        // Métodos
        // Getters
        int getNTiendas();
        Heap** getHeaps();
        // Setters
        void setNTiendas(int newNTiendas);
        void setHeaps(Heap** newHeaps);
        // Otros Métodos
        bool readFile(string fileName);
        int findTiendaMinArista();
        Grafo* MSTPrim();
        void printGrafo();
};

#endif