#include "Heap.h"

int main() {
    Heap *heap = new Heap(2);
    StateRH* s0 = new StateRH();
    StateRH* s1 = new StateRH();
    StateRH* s2 = new StateRH();
    StateRH* s3 = new StateRH();
    StateRH* s4 = new StateRH();

    s0->setHeurValue(6);
    s1->setHeurValue(4);
    s2->setHeurValue(1);
    s3->setHeurValue(3);
    s4->setHeurValue(20);


    heap->push(s0);
    heap->push(s1);
    heap->push(s2);
    heap->push(s3);
    heap->push(s4);

    while (!heap->isEmpty()) {
        StateRH* state = heap->pop();
        cout << "State: " << state->getHeurValue() << endl;
    }

}