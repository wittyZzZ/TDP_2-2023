#include <iostream>
#include "RHGame.h"
#include "ctime"
using namespace std;

int main() {

    bool salir = false;
    bool existeArchivo = true;
    int opcion;
    string inputString;
    string inputString2;
    time_t start,end;
    double timeTaken;
    
    cout<<endl;
    cout << "#########################################################" <<endl;
    cout << "Bienvenido al programa de soluciones del juego Rush Hour!" <<endl;
    cout << "#########################################################" <<endl;
    cout<<endl;

    while (!salir) {

        cout << "Ingrese el nombre del archivo que contiene los datos de los autos (Ejemplo: juego.txt): ";
        getline(cin,inputString);
        cout<<endl;
        cout << "Ingrese el nombre del archivo que contiene los datos de las paredes (Ejemplo: paredes.txt): ";
        getline(cin,inputString2);
        cout<<endl;

        RHGame* game = new RHGame();
        StateRH* initial = new StateRH();

        existeArchivo = game->readFile(inputString,inputString2,initial);

        if (existeArchivo) {
            cout<<endl;
            cout<< "Autos existentes en el juego: "<<endl;
            cout<<endl;

            Car** car = initial->getCars();
            for (int i = 0; i < game->getCarsCount();i++) {
                std::cout << i << " ";
                car[i]->print();
            }

            cout<<endl;
            cout<< "Tablero de juego inicial:"<<endl;
            cout<<endl;
            initial->printRhBoard();
            cout<<endl;

            time(&start);

            StateRH* resolution = game->solver(initial);

            time(&end);

            timeTaken = double(end-start);

            if (resolution != nullptr) {
                cout << "Tiempo de resolucion: " << timeTaken << endl;

                cout<<endl;
                cout<< "Tablero de juego final:"<<endl;
                cout<<endl;
                resolution->printRhBoard();
            } else {
                cout << "El puzzle no tiene solucion..." << endl;
            }
            delete game;
            delete resolution;
        } else {
            delete initial;
            delete game;
        }

        cout << endl;
        cout << "¿Desea seguir calculando soluciones?" <<endl;
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