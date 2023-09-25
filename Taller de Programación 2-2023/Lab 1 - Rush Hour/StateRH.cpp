#include "StateRH.h"
using namespace std;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ######################################################################### CONSTRUCTOR ###############################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

StateRH::StateRH() {
    this->heurValue = 0;
    this->carsCount = 0;
    this->cars = new Car*[18];
    this->redCarSymbol = '0';
    this->move = "Start";
    this->father = nullptr;
    this->rhBoard = new char*[6];
    for (int i = 0;i < 6;i++) {
        this->rhBoard[i] = new char[6];
        for (int j = 0;j < 6;j++) {
            this->rhBoard[i][j] = '0';
        }
    }
}

// DESTRUCTOR
StateRH::~StateRH() {
    for (int i = 0;i < 6;i++) {
        delete[] this->rhBoard[i];
    }
    delete[] this->rhBoard;
    for (int i = 0;i < this->carsCount;i++) {
        delete this->cars[i];
    }
    delete[] this->cars;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ########################################################################## MÉTODOS ##################################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Getters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
getHeurValue
Descripción: Método que retorna el valor de heuristica de el StateRH
Entrada: void
Salida: El valor de heuristica (int)
*/
int StateRH::getHeurValue() {
    return this->heurValue;
}

/*
getCars
Descripción: Método que retorna los Cars de el StateRH
Entrada: void
Salida: Los Cars (Car**)
*/
Car** StateRH::getCars() {
    return this->cars;
}

/*
getCarsCount
Descripción: Método que retorna la cantidad de Cars de el StateRH
Entrada: void
Salida: La cantidad de Cars (int)
*/
int StateRH::getCarsCount() {
    return this->carsCount;
}

/*
getRedCarSymbol
Descripción: Método que retorna el símbolo del Car rojo de el StateRH
Entrada: void
Salida: El símbolo del Car rojo (char)
*/
char StateRH::getRedCarSymbol() {
    return this->redCarSymbol;
}

/*
getBoard
Descripción: Método que retorna el tablero de juego de el StateRH
Entrada: void
Salida: El tablero de juego (char**)
*/
char** StateRH::getBoard() {
    return this->rhBoard;
}

/*
getMove
Descripción: Método que retorna el movimiento con el cual se generó el StateRH
Entrada: void
Salida: El movimiento (string)
*/
string StateRH::getMove() {
    return this->move;
}

/*
getFather
Descripción: Método que retorna el StateRH padre del StateRH
Entrada: void
Salida: El StateRH padre (StateRH*)
*/
StateRH* StateRH::getFather() {
    return this->father;
}
// Setters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
setHeurValue
Descripción: Método que modifica el valor de heuristica del StateRH
Entrada: Nuevo valor de heuristica (int)
Salida: void
*/
void StateRH::setHeurValue(int heurValue) {
    this->heurValue = heurValue; 
}

/*
setCarsCount
Descripción: Método que modifica la cantidad de Cars del StateRH
Entrada: Nuevo valor de Cars (int)
Salida: void
*/
void StateRH::setCarsCount(int carsCount) {
    this->carsCount = carsCount;
}

/*
setCars
Descripción: Método que modifica los Cars del StateRH
Entrada: Nuevos Cars (Car**)
Salida: void
*/
void StateRH::setCars(Car** cars) {
    this->cars = cars;
}

/*
setRedCarSymbol
Descripción: Método que modifica el simbolo del Car rojo del StateRH
Entrada: Nuevo simbolo de Car rojo (char)
Salida: void
*/
void StateRH::setRedCarSymbol(char symbol) {
    this->redCarSymbol = symbol;
}

/*
setRhBoard
Descripción: Método que modifica el tablero de juego del StateRH
Entrada: Nuevo tablero de juego (char**)
Salida: void
*/
void StateRH::setRhBoard(char** rhBoard) {
    this->rhBoard = rhBoard;
}

/*
setMove
Descripción: Método que modifica el movimiento del StateRH
Entrada: Nuevo movimiento (string)
Salida: void
*/
void StateRH::setMove(string move) {
    this->move = move;
}

/*
setFather
Descripción: Método que modifica el StateRH padre del StateRH
Entrada: Nuevo StateRH padre (StateRH*)
Salida: void
*/
void StateRH::setFather(StateRH* father) {
    this->father = father;
}

// OTROS MÉTODOS
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
printRhBoard
Descripción: Método que imprime el tablero de juego del StateRH
Entrada: void
Salida: void
*/
void StateRH::printRhBoard() {
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 6;j++) {
            std::cout << this->rhBoard[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}

/*
copyState
Descripción: Método que copia los datos del StateRH generando otro igual
Entrada: void
Salida: El StateRH copia (StateRH*)
*/
StateRH* StateRH::copyState() {
    StateRH* newState = new StateRH();
    newState->setHeurValue(this->heurValue);
    newState->setRedCarSymbol(this->redCarSymbol);
    newState->setCarsCount(this->carsCount);
    Car** cars = newState->getCars();
    for (int i = 0;i < this->carsCount;i++) {
        cars[i] = this->cars[i]->copyCar();
    }
    newState->setCars(cars);
    char** newBoard = newState->getBoard();
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 6;j++) {
            newBoard[i][j] = this->rhBoard[i][j];
        }
    }
    newState->setRhBoard(newBoard);
    return newState;
}

/*
isSolved
Descripción: Método que verifica si el tablero de juego del StateRH esta resuelto 
Entrada: void
Salida: Resultado de si esta resuelto o no (bool)
*/
bool StateRH::isSolved() {
    for (int i = 5;i > 0;i--) {
        if (this->rhBoard[2][i] != '0') {
            return this->rhBoard[2][i] == this->redCarSymbol;
        }
    }
    return false;
}

/*
isEqualBoard
Descripción: Método que verifica si el tablero de juego del StateRH es igual a otro
Entrada: El tablero de juego a comparar (char**)
Salida: Resultado de si es igual o no (bool)
*/
bool StateRH::isEqualBoard(char** board) {
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 6;j++) {
            if (this->rhBoard[i][j] != board[i][j]) {
                return false;
            }
        }
    }
    return true;
}

/*
printMoves
Descripción: Método que imprime los movimientos que ocurrieron para llegar al StateRH 
Entrada: void
Salida: void
*/
void StateRH::printMoves() {
    if (this->father != nullptr) {
        this->father->printMoves();
    }
    cout << this->move << endl;
}

/*
makeHeurValue
Descripción: Método que retorna el valor de heuristica de el StateRH
Entrada: void
Salida: Valor de heuristica (int)
*/
int StateRH::makeHeurValue() {
    int heurValue = 0;
    int y = 0;
    for (int i = 0;i < this->carsCount;i++) {
        if (this->cars[i]->getSymbol() == this->redCarSymbol) {
            int y = this->cars[i]->getY();
            for (int j = y + 1;j < 6;j++) {
                if (this->rhBoard[2][j] != '0' && this->rhBoard[2][j] != this->redCarSymbol) {
                    heurValue++;
                }
            }
            return heurValue;
        }
    }
    return heurValue;
}