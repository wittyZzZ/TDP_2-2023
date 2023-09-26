FLAGS = -g
main: Car.o StateRH.o Heap.o RHGame.o main.cpp
	g++ ${FLAGS} RHGame.o Car.o StateRH.o Heap.o main.cpp -o main -O0 -g
RHGame.o: Heap.o RHGame.cpp RHGame.h
	g++ ${FLAGS} -c RHGame.cpp
Heap.o: StateRH.o Heap.cpp Heap.h
	g++ ${FLAGS} -c Heap.cpp 
StateRH.o: Car.o StateRH.cpp StateRH.h
	g++ ${FLAGS} -c StateRH.cpp
Car.o: Car.cpp Car.h 
	g++ ${FLAGS} -c Car.cpp
clean:
	rm -rf *.o main