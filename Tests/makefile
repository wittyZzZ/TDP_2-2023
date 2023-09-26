all: test_Heap test_State
test_Heap: test_Heap.cpp Heap.o State.o
	g++ -o test_Heap State.o Heap.o test_Heap.cpp
Heap.o: Heap.cpp Heap.h
	g++ -c Heap.cpp
test_State: test_State.cpp State.o
	g++ -o test_State State.o test_State.cpp
State.o: State.cpp State.h
	g++ -c State.cpp 
clean:
# rm -f test_Heap test_State *.o
	del *.o