all: main test_Heap test_Tienda test_Grafo
FLAGS = -O2

main: main.cpp Grafo.o Heap.o Tienda.o
	g++ ${FLAGS} Grafo.o Heap.o Tienda.o main.cpp -o main 

test_Grafo: test_Grafo.cpp Grafo.o Tienda.o Heap.o
	g++ ${FLAGS} Tienda.o Heap.o Grafo.o test_Grafo.cpp -o test_Grafo

test_Heap: test_Heap.cpp Heap.o Tienda.o
	g++ ${FLAGS} Tienda.o Heap.o test_Heap.cpp -o test_Heap

test_Tienda: test_Tienda.cpp Tienda.o
	g++ ${FLAGS} Tienda.o test_Tienda.cpp -o test_Tienda

Grafo.o: Heap.o Grafo.cpp Grafo.h
	g++ ${FLAGS} -c Grafo.cpp

Heap.o: Tienda.o Heap.cpp Heap.h
	g++ ${FLAGS} -c Heap.cpp 

Tienda.o: Tienda.cpp Tienda.h 
	g++ ${FLAGS} -c Tienda.cpp

clean:
	rm -rf *.o main test_Grafo test_Heap test_Tienda