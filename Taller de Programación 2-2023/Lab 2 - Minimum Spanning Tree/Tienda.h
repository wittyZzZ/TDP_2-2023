#include <iostream>
using namespace std;

class Tienda {
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
        
    private:
        // Atributos
        int id;
        int costo;
};