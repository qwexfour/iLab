
all: a.out

a.out: main.o asslib.o
	g++ main.o asslib.o -o a.out
main.o: main.cpp asslib.h
	g++ -c main.cpp -o main.o
asslib.o: asslib.cpp asslib.h
	g++ -c asslib.cpp -o asslib.o
clear:
	rm *.o a.out
