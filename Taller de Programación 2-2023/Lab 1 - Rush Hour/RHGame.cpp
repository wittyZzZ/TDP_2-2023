#include "RHGame.h"
using namespace std;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ######################################################################### CONSTRUCTOR ###############################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

RHGame::RHGame() {
    this->carsCount = 0;
    this->wallsCount = 0;
    this->board = new char*[6];
    for (int i = 0;i < 6;i++) {
        this->board[i] = new char[6];
        for (int j = 0;j < 6;j++) {
            this->board[i][j] = '0';
        }
    }
}

// DESTRUCTOR
RHGame::~RHGame() {
    for (int i = 0;i < 6;i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ########################################################################## MÉTODOS ##################################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Getters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
getCarsCount
Descripción: Método que retorna el número de Cars del RHGame
Entrada: void
Salida: El número de Cars (int)
*/
int RHGame::getCarsCount() {
    return this->carsCount;
}

/*
getWallsCount
Descripción: Método que retorna el número de paredes del RHGame
Entrada: void
Salida: El número de paredes (int)
*/
int RHGame::getWallsCount() {
    return this->wallsCount;
}

/*
getBoard
Descripción: Método que retorna el tablero de juego del RHGame
Entrada: void
Salida: El tablero de juego (char**)
*/
char** RHGame::getBoard() {
    return this->board;
}

// Setters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
setCarsCount
Descripción: Método que modifica el número de Cars del RHGame
Entrada: Nuevo número de Cars (int)
Salida: void
*/
void RHGame::setCarsCount(int carsCount) {
    this->carsCount = carsCount;
}

/*
setWallsCount
Descripción: Método que modifica el número de paredes del RHGame
Entrada: Nuevo número de paredes (int)
Salida: void
*/
void RHGame::setWallsCount(int wallsCount) {
    this->wallsCount = wallsCount;
}

/*
setBoard
Descripción: Método que modifica el tablero de juego del RHGame
Entrada: Nuevo tablero de juego (char**)
Salida: void
*/
void RHGame::setBoard(char** board) {
    this->board = board;
}

// OTROS MÉTODOS
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
readFile
Descripción: Método que abre, lee y guarda los datos de los archivos dentro de un StateRH*
Entrada: Nombre de Archivo de Autos (string) X Nombre de Archivo de Paredes (string) X Puntero a un StateRH (StateRH*) 
Salida: void
*/

// ARREGLAR ENTRADA DE PAREDES
// ARREGLAR ENTRADA DE PAREDES
// ARREGLAR ENTRADA DE PAREDES
// ARREGLAR ENTRADA DE PAREDES
// ARREGLAR ENTRADA DE PAREDES
// ARREGLAR ENTRADA DE PAREDES
// ARREGLAR ENTRADA DE PAREDES
// ARREGLAR ENTRADA DE PAREDES

void RHGame::readFile(string carsFile,string wallsFile,StateRH* initial) {
    int x, y, largo, dir;
    ifstream file(carsFile); // es un stream de "FileInput" desde un archivo. 
    string line; // es un objeto que representa un arreglo de char que es auto ajustable.
    int count = 0; // cuenta la cantidad de autos (uno por linea)
    char symbols[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R'};
    Car** cars = initial->getCars();
    while (getline(file, line)) { // lee una linea del archivo y la guarda en "line". Si no hay mas lineas, sale del while(retorna false).
        stringstream charStream; // es un stream de "StringInput" desde un string.
        charStream << line; // guarda el string en el stream
        charStream >> x >> y >> largo >> dir; // lee los datos del stream y los guarda en las variables. Notar que como es un input stream se usa la operacion inversa a <<, que es >>. Automaticamente lee el tipo de dato de cada variable.
        if (x == 2 && dir == HORIZONTAL) {
            initial->setRedCarSymbol(symbols[count]);
        }
        cars[count] = new Car(x,y,dir,largo,symbols[count]);
        count++;
    }

    initial->setCarsCount(count);

    this->carsCount = count;

    file.close(); // cerramos el archivo

    int numberWalls = 0;
    file.open(wallsFile);

    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
            stringstream charStream;
            charStream << line;
            charStream >> x >> y;
            this->board[x][y] = '#'; // guardamos la pared en la matriz
            numberWalls++;
        }
    } 

    this->wallsCount = numberWalls;
    makeRhBoard(initial);
    initial->setHeurValue(initial->makeHeurValue());
}

/*
printBoard
Descripción: Método que imprime el tablero de juego del RHGame
Entrada: void
Salida: void
*/
void RHGame::printBoard() {
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 6;j++) {
            std::cout << this->board[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}

/*
printBoard
Descripción: Método que genera un tablero de juego según los datos de un StateRH
Entrada: StateRH*
Salida: void
*/
void RHGame::makeRhBoard(StateRH* s) {
    Car** cars = s->getCars();
    char** board = s->getBoard();
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 6;j++) {
            board[i][j] = this->board[i][j]; // Se copia el tablero de RHGame al de StateRH por si se guardaron paredes en el de RHGame
        }
    }
    for (int i = 0;i < this->carsCount;i++) {
        int x = cars[i]->getX();
        int y = cars[i]->getY();
        int dir = cars[i]->getDir();
        int largo = cars[i]->getLargo();
        if (dir == HORIZONTAL) {
            for (int j = 0;j < largo;j++) {
                board[x][y+j] = cars[i]->getSymbol();
            }
        } else {
            for (int j = 0;j < largo;j++) {
                board[x+j][y] = cars[i]->getSymbol();
            }
        }
    }
}

/*
operate
Descripción: Método que genera un estado (StateRH) a partir de otro, haciendo una operación con uno de sus Cars
Entrada: StateRH* X Posición del Car (int) X Posición del movimiento (int)
Salida: Nuevo estado (StateRH*)
*/
StateRH* RHGame::operate(StateRH* s,int carPos,int stepPos) {
    StateRH* newState = s->copyState();
    char** tBoard = newState->getBoard();
    Car** cars = newState->getCars();    
    Car* tCar = cars[carPos];
    // SE EXTRAEN LOS DATOS DEL AUTO OBJETIVO
    int x = tCar->getX();
    int y = tCar->getY();
    int dir = tCar->getDir();
    int largo = tCar->getLargo();
    char symbol = tCar->getSymbol();
    int* tSteps = tCar->getPossibleSteps();
    int step = tSteps[stepPos];
    // CASOS SI LA ORIENTACIÓN DEL AUTO ES HORIZONTAL O VERTICAL
    if (dir == HORIZONTAL) {
        if (y + step >= 0 && y + largo + step - 1 <= 5) {
            // CASOS SI EL STEP ES NEGATIVO O POSITIVO
            if (step < 0) {
                for (int i = y + step;i < y;i++) {
                    if (tBoard[x][i] != '0') {
                        return nullptr;
                    }
                }
            } else {
                for (int i = y + largo;i < y + largo + step;i++) {
                    if (tBoard[x][i] != '0') {
                        return nullptr;
                    }
                }
            }
            // SE PUEDE HACER LA OPERACION
            // ELIMINAR AUTO DE CELDAS ORIGINALES
            for (int i = y;i < y + largo;i++) {
                tBoard[x][i] = '0';
            }
            // CREAR AUTO EN NUEVAS CELDAS
            for (int i = y + step;i < y + step + largo;i++) {
                tBoard[x][i] = symbol; 
            }
            tCar->setY(y + step);
            newState->setFather(s);
            string move = "Auto ";
            move = move + symbol + ": ";
            int stepAbs = abs(step);
            if (step < 0) {
                move = move + to_string(stepAbs) + " LEFT";
            } else {
                move = move + to_string(stepAbs) + " RIGHT";
            }
            newState->setMove(move);
            return newState;
        } else {
            return nullptr;
        }
    } else {
        if (x + step >= 0 && x + largo + step - 1 <= 5) {
            // CASOS SI EL STEP ES NEGATIVO O POSITIVO
            if (step < 0) {
                for (int i = x + step;i < x;i++) {
                    if (tBoard[i][y] != '0') {
                        return nullptr;
                    }
                }
            } else {
                for (int i = x + largo;i < x + largo + step;i++) {
                    if (tBoard[i][y] != '0') {
                        return nullptr;
                    }
                }
            }
            // SE PUEDE HACER LA OPERACION
            // ELIMINAR AUTO DE CELDAS ORIGINALES
            for (int i = x;i < x + largo;i++) {
                tBoard[i][y] = '0';
            }
            // CREAR AUTO EN NUEVAS CELDAS
            for (int i = x + step;i < x + step + largo;i++) {
                tBoard[i][y] = symbol; 
            }
            tCar->setX(x + step);
            newState->setFather(s);
            string move = "Auto ";
            move = move + symbol + ": ";
            int stepAbs = abs(step);
            if (step < 0) {
                move = move + to_string(stepAbs) + " UP";
            } else {
                move = move + to_string(stepAbs) + " DOWN";
            }
            newState->setMove(move);
            return newState;
        } else {
            return nullptr;
        }
    }
}

/*
operate2
Descripción: Método que genera un estado (StateRH) a partir de otro, haciendo una operación con uno de sus Cars.
Realiza lo mismo que "operate" pero este recibe directamente el valor del movimiento que se quiere realizar y no el indice de donde esta el mismo
Entrada: StateRH* X Posición del Car (int) X Valor del movimiento (int)
Salida: Nuevo estado (StateRH*)
*/
StateRH* RHGame::operate2(StateRH* s,int carPos,int step) {
    StateRH* newState = s->copyState();
    char** tBoard = newState->getBoard();
    Car** cars = newState->getCars();    
    Car* tCar = cars[carPos];
    // SE EXTRAEN LOS DATOS DEL AUTO OBJETIVO
    int x = tCar->getX();
    int y = tCar->getY();
    int dir = tCar->getDir();
    int largo = tCar->getLargo();
    char symbol = tCar->getSymbol();
    // CASOS SI LA ORIENTACIÓN DEL AUTO ES HORIZONTAL O VERTICAL
    if (dir == HORIZONTAL) {
        if (y + step >= 0 && y + largo + step - 1 <= 5) {
            // CASOS SI EL STEP ES NEGATIVO O POSITIVO
            if (step < 0) {
                for (int i = y + step;i < y;i++) {
                    if (tBoard[x][i] != '0') {
                        return nullptr;
                    }
                }
            } else {
                for (int i = y + largo;i < y + largo + step;i++) {
                    if (tBoard[x][i] != '0') {
                        return nullptr;
                    }
                }
            }
            // SE PUEDE HACER LA OPERACION
            // ELIMINAR AUTO DE CELDAS ORIGINALES
            for (int i = y;i < y + largo;i++) {
                tBoard[x][i] = '0';
            }
            // CREAR AUTO EN NUEVAS CELDAS
            for (int i = y + step;i < y + step + largo;i++) {
                tBoard[x][i] = symbol; 
            }
            tCar->setY(y + step);
            newState->setFather(s);
            string move = "Auto ";
            move = move + symbol + ": ";
            int stepAbs = abs(step);
            if (step < 0) {
                move = move + to_string(stepAbs) + " LEFT";
            } else {
                move = move + to_string(stepAbs) + " RIGHT";
            }
            newState->setMove(move);
            return newState;
        } else {
            return nullptr;
        }
    } else {
        if (x + step >= 0 && x + largo + step - 1 <= 5) {
            // CASOS SI EL STEP ES NEGATIVO O POSITIVO
            if (step < 0) {
                for (int i = x + step;i < x;i++) {
                    if (tBoard[i][y] != '0') {
                        return nullptr;
                    }
                }
            } else {
                for (int i = x + largo;i < x + largo + step;i++) {
                    if (tBoard[i][y] != '0') {
                        return nullptr;
                    }
                }
            }
            // SE PUEDE HACER LA OPERACION
            // ELIMINAR AUTO DE CELDAS ORIGINALES
            for (int i = x;i < x + largo;i++) {
                tBoard[i][y] = '0';
            }
            // CREAR AUTO EN NUEVAS CELDAS
            for (int i = x + step;i < x + step + largo;i++) {
                tBoard[i][y] = symbol; 
            }
            tCar->setX(x + step);
            newState->setFather(s);
            string move = "Auto ";
            move = move + symbol + ": ";
            int stepAbs = abs(step);
            if (step < 0) {
                move = move + to_string(stepAbs) + " UP";
            } else {
                move = move + to_string(stepAbs) + " DOWN";
            }
            newState->setMove(move);
            return newState;
        } else {
            return nullptr;
        }
    }
}

/*
solver
Descripción: Método que resuelve y entrega el estado final (StateRH) del juego ya resuelto (usa el Algoritmo A* y una Heuristica)
Entrada: El estado inicial del juego (StateRH*)
Salida: El estado final resuelto (StateRH*)
*/ 
StateRH* RHGame::solver(StateRH* initial) {
    Stack toVisit(1);
    Stack visited(1);
    toVisit.push(initial);
    while (!toVisit.isEmpty()) {
        StateRH* actual = toVisit.pop();
        visited.push(actual);
        if (actual->isSolved()) {
            cout << "STACK VISITADOS: " << visited.size << endl;
            cout << "STACK POR VISITAR: " << toVisit.size << endl;
            return actual;
        }
        Car** cars = actual->getCars();
        for (int i = 0;i < actual->getCarsCount();i++) {
            int* tSteps = cars[i]->getPossibleSteps();
            for (int j = 0;j < cars[i]->getStepCount();j++) {
                StateRH* newState = operate(actual,i,j);
                if (newState != nullptr && !toVisit.contains(newState)
                && !visited.contains(newState)) {
                    newState->setHeurValue(newState->makeHeurValue());
                    toVisit.push(newState);
                    toVisit.quickSort(toVisit.stack,0,toVisit.size-1);
                }
            }
        }
    }
    return nullptr;
}
