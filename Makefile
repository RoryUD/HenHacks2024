run: all
	make all
	./main

all: main

main: main.o SentenceConstructor.o
	g++ -o main main.o SentenceConstructor.o

main.o: main.cpp
	g++ -c main.cpp

SentenceConstructor.o: SentenceConstructor.hh
	g++ -o SentenceConstructor.o SentenceConstructor.hh

clean:
	rm -f *.o main