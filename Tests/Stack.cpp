#include "Stack.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ######################################################################### CONSTRUCTOR ###############################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Stack::Stack(int size) {
    this->size = size;
    this->top = -1;
    this->stack = new StateRH*[size];
}

// DESTRUCTOR
Stack::~Stack() {
    delete[] this->stack;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ########################################################################## MÉTODOS ##################################################################################
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
isEmpty
Descripción: Método que verifica si el Stack esta vacío o no
Entrada: void
Salida: Resultado de si esta vacío o no (bool)
*/
bool Stack::isEmpty() {
    return this->top == -1;
}

/*
Push
Descripción: Método que agrega un Estado al Stack
Entrada: El estado a agregar (StateRH*)
Salida: void
*/
void Stack::push(StateRH* state) {
    if (this->top == this->size - 1) {
        StateRH** newStack = new StateRH*[this->size + 1];
        for (int i = 0;i < this->size;i++) {
            newStack[i] = this->stack[i];
        }
        delete[] this->stack;
        this->stack = newStack;
        this->size ++;
    }
    this->top++;
    this->stack[this->top] = state;
}

/*
Pop
Descripción: Método que expulsa un Estado del Stack
Entrada: void
Salida: El estado expulsado (StateRH*)
*/
StateRH* Stack::pop() {
    if (this->isEmpty()) {
        throw "El Stack esta vacio";
    } else {
        StateRH* state = this->stack[this->top];
        this->top--;
        return state;
    }
}

/*
Contains
Descripción: Método que verifica si un Estado ya esta dentro del Stack
Entrada: El Estado a revisar (StateRH*)
Salida: Resultado de si esta contenido o no (bool)
*/
bool Stack::contains(StateRH* state) {
    for (int i = 0;i < this->top+1;i++) {
        char** sBoard = stack[i]->getBoard();
        if (state->isEqualBoard(sBoard)) {
            return true;
        } 
    }
    return false;
}

/*
Partition
Descripción: Método que realiza una partición de los índices del Stack dependiendo de los valores de Heuristica de los Estados de este
Entrada: Un Stack de Estados (StateRH **stack) X Índice de comienzo (int) X Índice de termino (int)
Salida: El índice pivote (int)
*/
int Stack::partition(StateRH **stack, int start, int end) {
    StateRH* pivot = stack[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (stack[i]->getHeurValue() >= pivot->getHeurValue())
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(stack[pivotIndex], stack[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (stack[i]->getHeurValue() >= pivot->getHeurValue()) {
            i++;
        }
 
        while (stack[j]->getHeurValue() < pivot->getHeurValue()) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(stack[i++], stack[j--]);
        }
    }
 
    return pivotIndex;
}

/*
quickSort
Descripción: Método que realiza el ordenamiento QuickSort en un Stack de sus Estados dependiendo del valor Heuristica de estos
Entrada: Un Stack de Estados (StateRH **stack) X Índice de comienzo (int) X Índice de termino (int)
Salida: void
*/
void Stack::quickSort(StateRH **stack, int start, int end) {
    // base case
    if (start >= end)
        return;
 
    // partitioning the stackay
    int p = partition(stack, start, end);
 
    // Sorting the left part
    quickSort(stack, start, p - 1);
 
    // Sorting the right part
    quickSort(stack, p + 1, end);
}
