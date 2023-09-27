FLAGS = -g

main: Car.o StateRH.o Heap.o RHGame.o main.cpp
	g++ ${FLAGS} RHGame.o Car.o StateRH.o Heap.o main.cpp -o main
old: test_Heap.cpp Heap.o Car.o StateRH.o
	g++ ${FLAGS} Car.o StateRH.o Heap.o test_Heap.cpp -o old
RHGame.o: Heap.o RHGame.cpp RHGame.h
	g++ ${FLAGS} -c RHGame.cpp
Heap.o: StateRH.o Heap.cpp Heap.h
	g++ ${FLAGS} -c Heap.cpp 
StateRH.o: Car.o StateRH.cpp StateRH.h
	g++ ${FLAGS} -c StateRH.cpp
Car.o: Car.cpp Car.h 
	g++ ${FLAGS} -c Car.cpp
clean:
#rm -rf *.o main
	del *.o 
	del main.exe
