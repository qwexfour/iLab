
all: a.out

a.out: main.o disasslib.o
	g++ main.o disasslib.o -o a.out

main.o: main.cpp disasslib.h
	g++ -c main.cpp -o main.o

disasslib.o: disasslib.cpp disasslib.h
	g++ -c disasslib.cpp -o disasslib.o
clear:
	rm *.o a.out
