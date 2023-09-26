#include "State.h"

State::State(int value, State *parent) {
    this->value = value;
    this->parent = parent;
}

State::State() {
    this->value = 0;
    this->parent = nullptr;
}

State::~State() {
    // cout << "Deleting state with value: " << this->value << endl;
}

void State::print() {
    State *p=parent;
    if (parent != nullptr) { // esto es recursion pre-order
        p->print();
    }
    cout << "State value: " << this->value << endl;
}