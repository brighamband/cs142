makefile: main.o Ornament.o
	g++ -o makefile main.o Ornament.o
		
main.o: main.cpp Ornament.h
	g++ -c main.cpp

Ornament.o: Ornament.cpp Ornament.h
	g++ -c Ornament.cpp