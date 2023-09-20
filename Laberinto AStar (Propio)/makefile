FLAGS = -g
main: Stack.o  main.cpp State.o Operation.o Maze.o
	g++ ${FLAGS} State.o Stack.o Operation.o Maze.o main.cpp -o main 
Maze.o: Maze.cpp Maze.h
	g++ ${FLAGS} -c Maze.cpp
Stack.o: State.o Stack.cpp Stack.h
	g++ ${FLAGS} -c Stack.cpp
State.o: State.cpp State.h
	g++ ${FLAGS} -c State.cpp
Operation.o: Operation.cpp Operation.h
	g++ ${FLAGS} -c Operation.cpp
clean:
	del *.o
	del *.exe