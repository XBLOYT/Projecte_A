all: programa

programa: MiClase.o main.o
	g++ -o programa graf.o main.o

MiClase.o: graf.cpp graf.h
	g++ -c graf.cpp

main.o: main.cpp graf.h
	g++ -c main.cpp

clean:
	rm -f programa *.o