#include "Tienda.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ################################################################### CONSTRUCTOR & DESTRUCTOR ########################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
Tienda (Constructor)
Descripción: Método que crea una Tienda dado un ID y un costo
Entrada: ID de Tienda (int) X Costo (int)
Salida: void
*/
Tienda::Tienda(int id, int costo) {
    this->id = id;
    this->costo = costo;
}

/*
~Tienda (Destructor)
Descripción: Método que elimina una instancia de Tienda
Entrada: void
Salida: void
*/ 
Tienda::~Tienda() {}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ########################################################################## MÉTODOS ##################################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Getters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
getId
Descripción: Método que retorna el id de una clase Tienda
Entrada: void
Salida: Id de la Tienda (int)
*/
int Tienda::getId() {
    return this->id;
}

/*
getCosto
Descripción: Método que retorna el costo de una clase Tienda
Entrada: void
Salida: Costo de la Tienda (int)
*/
int Tienda::getCosto() {
    return this->costo;
}

// Setters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
setId
Descripción: Método que modifica el id de una clase Tienda
Entrada: Nuevo id (int)
Salida: void
*/
void Tienda::setId(int newId) {
    this->id = newId;
}

/*
setCosto
Descripción: Método que modifica el costo de una clase Tienda
Entrada: Nuevo costo (int)
Salida: void
*/
void Tienda::setCosto(int newCosto) {
    this->costo = newCosto;
}

// OTROS MÉTODOS
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
printTienda
Descripción: Método que imprime los datos de una clase Tienda
Entrada: void
Salida: void
*/
void Tienda::printTienda() {
    cout << "Tienda: " << this->id << "; Costo: " << this->costo;
}