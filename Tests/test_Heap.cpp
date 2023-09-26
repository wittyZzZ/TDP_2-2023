#include "Heap.h"

int main() {
    Heap *heap = new Heap(2);
    State *root = new State(4,nullptr);
    State *s1 = new State(1,root);
    State *s2 = new State(5,s1);
    State *s3 = new State(3,s2);
    State *s4 = new State(2,s3);

    heap->push(root);
    heap->push(s1);
    heap->push(s2);
    heap->push(s3);
    heap->push(s4);

    while (!heap->isEmpty()) {
        State *state = heap->pop();
        cout << "State: " << state->value << endl;
    }

}