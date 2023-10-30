#ifndef Tienda_h
#define Tienda_h

#include <iostream>

using namespace std;

/*
    > Clase Tienda:

    Esta clase se usa para representar una tienda. Cumple el mismo propósito que lo que se 
    conoce como "nodo".

    Esta clase es representada por: ID (int) X Costo (int)

*/

class Tienda {
    private:
        // Atributos
        int id;
        int costo;
    public:
        // Constructor
        Tienda(int id,int costo);
        // Destructor
        ~Tienda();
        // Métodos
        // Getters
        int getId();
        int getCosto();
        // Setters
        void setId(int newId);
        void setCosto(int newCosto);
        // Otros Métodos
        void printTienda();
};

#endif