#include "Grafo.h"
#include "ctime"
#include <iomanip>

using namespace std;

int main() {

    bool salir = false;
    bool existeArchivo = true;
    int opcion;
    string inputString;
    time_t start,end;
    double timeTaken;
    
    cout<<endl;
    cout << "#############################################################" <<endl;
    cout << "Bienvenido al programa de generacion de Arbol de Costo Minimo" <<endl;
    cout << "#############################################################" <<endl;
    cout<<endl;

    while (!salir) {

        cout << "Ingrese el nombre del archivo que contiene los datos de las tiendas (Ejemplo: file.txt): ";
        getline(cin,inputString);
        cout<<endl;

        Grafo* grafo = new Grafo();
        existeArchivo = grafo->readFile(inputString);

        if (existeArchivo) {
            
            time(&start);

            // Se genera Grafo MST a partir del inicial
            Grafo* mst = grafo->MSTKruskal();

            time(&end);
            timeTaken = double(end-start);

            if (mst != nullptr) {
                cout << "##################################" << endl << endl;
                cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                cout << "Tiempo de resolucion: " << fixed << setprecision(2) << timeTaken << endl;
                cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                cout<<endl;
                cout<< "~~~~~~~~~~~~~~~~~~~"<<endl;
                cout<< "Grafo MST generado:"<<endl;
                cout<< "~~~~~~~~~~~~~~~~~~~"<<endl;
                cout<<endl;
                mst->printGrafo();
                cout << "##################################" << endl;
            } else {
                cout << "El Grafo no tiene solucion..." << endl;
            }
            delete grafo;
            delete mst;
        } else {
            delete grafo;
            cout << "El archivo ingresado no es valido..." << endl;
        }

        cout << endl;
        cout << "Desea seguir generando MST?" <<endl;
        cout << endl;
        cout << "1. Probar con otros archivos de entrada" <<endl;
        cout << "2. Salir" << endl;
        cout << "INGRESE SU OPCION: ";
        cin >> opcion;
        cout<<endl;

        switch (opcion) {
        case 1:
            cout << "Usted selecciono \"Probar con otros archivos de entrada\"" <<endl;
            cout<<endl;
            break;
        case 2:
            salir = true;
            cout << "Usted selecciono \"Salir\"" <<endl;
            cout<<endl;
            cout<< "FIN DEL PROGRAMA..."<<endl;
            break;
        default:
            salir = true;
            cout << "Usted selecciono \"Salir\"" <<endl;
            cout<<endl;
            cout<< "FIN DEL PROGRAMA..."<<endl;
            break;
        }
        cin.ignore();
    }
    return 0;
}