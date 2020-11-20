#Makefile
Tags= -pedantic-errors -std=c++11

Intro.o: Intro.cpp Intro.h
	g++ $(Tags) -c $<

puzzle.o: puzzle.cpp puzzle.h
		g++ $(Tags) -c $<

main.cpp: main.cpp Intro.h
	g++ $(Tags) -c $<

Hunt: main.o Intro.o puzzle.o
	g++ $(Tags) $^ -o Hunt

clean:
		rm -f Hunt *.o *.txt

.PHOONY: clean
