all: main test_Heap test_StateRH test_Car test_RHGame
FLAGS = -O2

main: main.cpp RHGame.o Car.o StateRH.o Heap.o 
	g++ ${FLAGS} RHGame.o Car.o StateRH.o Heap.o main.cpp -o main 

test_RHGame: test_RHGame.cpp RHGame.o Car.o StateRH.o Heap.o 
	g++ ${FLAGS} RHGame.o Car.o StateRH.o Heap.o test_RHGame.cpp -o test_RHGame

test_Heap: test_Heap.cpp Heap.o Car.o StateRH.o
	g++ ${FLAGS} Car.o StateRH.o Heap.o test_Heap.cpp -o test_Heap

test_StateRH: test_StateRH.cpp StateRH.o Car.o 
	g++ ${FLAGS} Car.o StateRH.o test_StateRH.cpp -o test_StateRH

test_Car: test_Car.cpp Car.o
	g++ ${FLAGS} Car.o test_Car.cpp -o test_Car

RHGame.o: RHGame.cpp RHGame.h
	g++ ${FLAGS} -c RHGame.cpp

Heap.o: Heap.cpp Heap.h
	g++ ${FLAGS} -c Heap.cpp 

StateRH.o: StateRH.cpp StateRH.h
	g++ ${FLAGS} -c StateRH.cpp

Car.o: Car.cpp Car.h 
	g++ ${FLAGS} -c Car.cpp

clean:
	rm -rf *.o main test_Heap test_StateRH test_Car test_RHGame

