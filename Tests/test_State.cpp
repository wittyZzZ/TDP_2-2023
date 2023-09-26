#include "State.h"

int main() {
    State *root = new State(1,nullptr);
    State *s1 = new State(2,root);
    State *s2 = new State(3,s1);
    State *s3 = new State(4,s2);

    s3->print(); // se testea la recursion pre-order
}