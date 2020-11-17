//Makefile
Tags= -pedantic-errors -std=c++11

Intro.o: Intro.cpp Intro.h
	g++ $(Tags) -c $<

main.cpp: main.cpp Intro.h
	g++ $(Tags) -c $<

The_Hunt: main.o Intro.o
	g++ $(Tags) $^ -o The_Hunt

clean:
		rm -f main.o Intro.o main *.txt

.PHOONY: clean
