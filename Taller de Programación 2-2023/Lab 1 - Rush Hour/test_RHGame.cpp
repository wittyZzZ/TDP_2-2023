#include "RHGame.h"

int main() {

    RHGame* game = new RHGame();
    StateRH* initial = new StateRH();

    // Prueba de metodo readFile
    game->readFile("testFile.txt","testFile2.txt",initial);

    // Prueba de metodo solver (Algoritmo A*)
    StateRH* resolution = game->solver(initial);
                    
    delete game;
    delete resolution;

    return 0;
}