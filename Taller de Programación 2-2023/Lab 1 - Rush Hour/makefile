FLAGS = -g
main: Car.o StateRH.o Stack.o RHGame.o main.cpp
	g++ ${FLAGS} RHGame.o Car.o StateRH.o Stack.o main.cpp -o main 
RHGame.o: Stack.o RHGame.cpp RHGame.h
	g++ ${FLAGS} -c RHGame.cpp
Stack.o: StateRH.o Stack.cpp Stack.h
	g++ ${FLAGS} -c Stack.cpp
StateRH.o: Car.o StateRH.cpp StateRH.h
	g++ ${FLAGS} -c StateRH.cpp
Car.o: Car.cpp Car.h 
	g++ ${FLAGS} -c Car.cpp
clean:

	rm -rf *.o main