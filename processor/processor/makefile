

all: a.out

a.out: main.o mystack.o proclib.o
	g++ main.o mystack.o proclib.o -o a.out
main.o: main.cpp proclib.h
	g++ -c main.cpp -o main.o
proclib.o: proclib.cpp proclib.h mystack.h
	g++ -c proclib.cpp -o proclib.o
mystack.o: mystack.cpp mystack.h
	g++ -c mystack.cpp -o mystack.o
clear:
	rm *.o a.out
