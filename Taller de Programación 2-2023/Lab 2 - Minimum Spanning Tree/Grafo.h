#include <iostream>
#include "Heap.h"
using namespace std;

/*
    > Clase Grafo:

    dadadadadadadadadadadada

*/
class Grafo {
    private:
        // Atributos
        int nTiendas;
        Heap **heapsAdyacencia;   
    public:
        // Constructor
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
};