#include "Grafo.h"

int main() {

    // Crear Grafo
    Grafo* grafo = new Grafo();

    // Leer archivo y almacenar datos en Grafo
    grafo->readFile("testFile.txt");

    // Imprimir Grafo

    // Se puede observar que el método "readFile" no almacena aristas redundantes, es decir, 
    // almacena el camino de Tienda1 a Tienda2, pero no de Tienda2 a Tienda1
    cout << endl;
    grafo->printGrafo();

    return 0;
}