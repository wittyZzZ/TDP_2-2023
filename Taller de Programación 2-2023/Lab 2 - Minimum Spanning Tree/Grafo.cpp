#include "Grafo.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ################################################################### CONSTRUCTOR & DESTRUCTOR ########################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
Grafo (Constructor)
Descripción: Método que crea un Grafo
Entrada: void
Salida: void
*/
Grafo::Grafo() {
    this->nTiendas = 0;
}

/*
Grafo (Constructor)
Descripción: Método que crea un Grafo dado un número de tiendas
Entrada: Número de tiendas (int)
Salida: void
*/
Grafo::Grafo(int nTiendas) {
    this->nTiendas = nTiendas;
    this->heapsAdyacencia = new Heap*[nTiendas];
    for (int i = 0;i < nTiendas;i++) {
        this->heapsAdyacencia[i] = new Heap(10);
    }
}

/*
Grafo (Destructor)
Descripción: Método que elimina una instancia de Grafo
Entrada: void
Salida: void
*/
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

/*
readFile
Descripción: Método que lee un archivo y modifica los datos del Grafo a partir del el
Entrada: Nombre del archivo (string)
Salida: True/False (bool)
*/
bool Grafo::readFile(string fileName) {
    // Contar lineas del archivo
    int nLineas = 0;
    ifstream archivo(fileName);
    string linea;
    while (getline (archivo, linea)) {
        nLineas++;
    }
    if (nLineas == 0) {
        return false;
    }
    this->nTiendas = nLineas;
    this->heapsAdyacencia = new Heap*[nLineas];
    // Inicializacion de los Heaps
    for (int i = 0;i < nLineas;i++) {
        this->heapsAdyacencia[i] = new Heap(10);
    }
    // Reposiciona el puntero de lectura al inico del archivo
    archivo.clear();
    archivo.seekg(0);
    // Guardar datos del archivo en Grafo
    int i = 0;
    while (getline (archivo, linea)) {
        int j = 0;
        for (char caracter: linea) {
            if (caracter != ' ') {
                if (j > i) {
                    if (caracter-'0' > 0) {
                        Tienda* newTienda = new Tienda(j,caracter-'0');
                        this->heapsAdyacencia[i]->push(newTienda);
                    }
                }
                j++;
            }
        }
        i++;
    }
    archivo.close();
    return true;
}

/*
findTiendaMinArista
Descripción: Método que retorna el id de la Tienda que tiene la conexion con el costo mas pequeño
Entrada: void
Salida: Id de la Tienda (int)
*/
int Grafo::findTiendaMinArista() {
    int costoMin = -1;
    int idTienda = 0;
    for (int i = 0;i < this->nTiendas;i++) {
        if (this->heapsAdyacencia[i]->isEmpty() != 1) {
            Tienda* x = this->heapsAdyacencia[i]->pop();
            if (costoMin == -1 || x->getCosto() < costoMin) {
                costoMin = x->getCosto();
                idTienda = i;
            } 
            this->heapsAdyacencia[i]->push(x);
        }
    }
    return idTienda;
}

/*
MSTPrim
Descripción: Método que genera un grafo de recubrimiento minimo a partir de otro Grafo usando el algoritmo de PRIM
Entrada: void
Salida: Grafo de recubrimiento mínimo (Grafo*)
*/
Grafo* Grafo::MSTPrim() {
    Grafo* mst = new Grafo(this->nTiendas);
    int visitados[this->nTiendas]; // 1 o 0
    int visitados2[this->nTiendas]; // Los numeros de las Tiendas visitadas
    for (int i = 0;i < this->nTiendas;i++) {
        visitados[i] = 0;
        visitados2[i] = -1;
    }
    int posTiendaMin = findTiendaMinArista();
    Tienda* temp = this->heapsAdyacencia[posTiendaMin]->pop();
    Tienda* x = new Tienda(posTiendaMin,temp->getCosto());
    mst->heapsAdyacencia[posTiendaMin]->push(temp);
    mst->heapsAdyacencia[temp->getId()]->push(x);
    // Se setean las variables de control de visitados
    int nVisitados = 2; visitados[posTiendaMin] = 1; visitados[temp->getId()] = 1; 
    visitados2[0] = posTiendaMin; visitados2[1] = temp->getId();

    while(nVisitados != this->nTiendas) {
        int costoMin = -1;
        int posVisitadoMin = -1;
        for (int i = 0;i < nVisitados;i++) {
            bool found = false;
            while (found == false) {
                if (this->heapsAdyacencia[visitados2[i]]->isEmpty() != 1) {
                    temp = this->heapsAdyacencia[visitados2[i]]->pop();
                    if (visitados[temp->getId()] == 0) {
                        if (costoMin == -1 || temp->getCosto() < costoMin) {
                            costoMin = temp->getCosto();
                            posVisitadoMin = i;
                        }
                        this->heapsAdyacencia[visitados2[i]]->push(temp);
                        found = true;
                    } else {
                        delete temp;
                    }
                } else {
                    found = true;
                }
            }
        }
        temp = this->heapsAdyacencia[visitados2[posVisitadoMin]]->pop();
        x = new Tienda(visitados2[posVisitadoMin],temp->getCosto());
        mst->heapsAdyacencia[visitados2[posVisitadoMin]]->push(temp);
        mst->heapsAdyacencia[temp->getId()]->push(x);
        visitados2[nVisitados] = temp->getId();
        visitados[temp->getId()] = 1;
        nVisitados++;
    }
    return mst;
}

/*
printGrafo
Descripción: Método que imprime por pantalla las conexiones del Grafo
Entrada: void
Salida: void
*/
void Grafo::printGrafo() {
    for (int i = 0;i < this->nTiendas;i++) {
        cout << "Conexiones Tienda " << i << ": " << endl;
        this->heapsAdyacencia[i]->printHeap();
        cout << endl;
    }
}