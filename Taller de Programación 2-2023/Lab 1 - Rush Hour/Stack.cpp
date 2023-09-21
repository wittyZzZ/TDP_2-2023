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

// isEmpty
bool Stack::isEmpty() {
    return this->top == -1;
}

// PUSH
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

// POP
StateRH* Stack::pop() {
    if (this->isEmpty()) {
        throw "El Stack esta vacio";
    } else {
        StateRH* state = this->stack[this->top];
        this->top--;
        return state;
    }
}

// PRINT
void Stack::print() {
    std::cout <<  "LOS OLD DEL PRINT:" << std::endl;
}


// CONTAINS
bool Stack::contains(StateRH* state) {
    for (int i = 0;i < this->top+1;i++) {
        char** sBoard = stack[i]->getBoard();
        if (state->isEqualBoard(sBoard)) {
            return true;
        } 
    }
    return false;
}

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
