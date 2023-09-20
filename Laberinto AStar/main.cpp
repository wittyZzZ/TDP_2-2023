#include <iostream>
#include "Maze.h"


int main() {
    State s[5] = {{1,2,UP,nullptr},
                {3,4,DOWN,nullptr},
                {5,6,LEFT,nullptr},
                {7,8,RIGHT,nullptr},
                {9,10,UP,nullptr} };
    Stack stack(5);

    for (int i=0; i<5; i++) {
        stack.push(&s[i]);
    }

    while (!stack.isEmpty()) {
        State *s = stack.pop();
        s->print();
    }
    cout<<"Testing Maze"<<endl;

    Maze maze(10);
    maze.print();
    State *solution = maze.solve(new State(0,0,UP,nullptr));
    if (solution != nullptr) {
        solution->print();
    } else {
        cout<<"No solution found"<<endl;
    }
}
