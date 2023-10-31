all: main test_Grafo test_Heap test_Tienda
FLAGS = -O2

main: main.cpp Grafo.o Heap.o Tienda.o
	g++ Grafo.o Heap.o Tienda.o main.cpp -o main -O0 -g

test_Grafo: test_Grafo.cpp Grafo.o Heap.o Tienda.o 
	g++ Grafo.o Heap.o Tienda.o test_Grafo.cpp -o test_Grafo -O0 -g

test_Heap: test_Heap.cpp Heap.o Tienda.o 
	g++ Heap.o Tienda.o test_Heap.cpp -o test_Heap -O0 -g

test_Tienda: test_Tienda.cpp Tienda.o 
	g++ Tienda.o test_Tienda.cpp -o test_Tienda -O0 -g

Grafo.o: Heap.o Grafo.cpp Grafo.h
	g++ -c Grafo.cpp

Heap.o: Tienda.o Heap.cpp Heap.h
	g++ -c Heap.cpp 

Tienda.o: Tienda.cpp Tienda.h 
	g++ -c Tienda.cpp

clean:
	rm -rf *.o main test_Grafo test_Tienda test_Heap