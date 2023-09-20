#include "StateRH.h"
using namespace std;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ######################################################################### CONSTRUCTOR ###############################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

StateRH::StateRH() {
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
    delete[] this->cars;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ########################################################################## MÉTODOS ##################################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Getters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Car** StateRH::getCars() {
    return this->cars;
}

int StateRH::getCarsCount() {
    return this->carsCount;
}

char StateRH::getRedCarSymbol() {
    return this->redCarSymbol;
}


char** StateRH::getBoard() {
    return this->rhBoard;
}

string StateRH::getMove() {
    return this->move;
}

StateRH* StateRH::getFather() {
    return this->father;
}
// Setters
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void StateRH::setCarsCount(int carsCount) {
    this->carsCount = carsCount;
}

void StateRH::setCars(Car** cars) {
    this->cars = cars;
}

void StateRH::setRedCarSymbol(char symbol) {
    this->redCarSymbol = symbol;
}

void StateRH::setRhBoard(char** rhBoard) {
    this->rhBoard = rhBoard;
}

void StateRH::setMove(string move) {
    this->move = move;
}

void StateRH::setFather(StateRH* father) {
    this->father = father;
}

// OTROS MÉTODOS
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void StateRH::printRhBoard() {
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 6;j++) {
            std::cout << this->rhBoard[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}

StateRH* StateRH::copyState() {
    StateRH* newState = new StateRH();
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

bool StateRH::isSolved() {
    for (int i = 5;i > 0;i--) {
        if (this->rhBoard[2][i] != '0') {
            return this->rhBoard[2][i] == this->redCarSymbol;
        }
    }
    return false;
}


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

void StateRH::printMoves() {
    if (this->father != nullptr) {
        this->father->printMoves();
    }
    cout << this->move << endl;
}