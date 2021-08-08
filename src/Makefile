program: main.o interface.o interface.h board.h board.o
	c++ -o ../build/program main.o interface.o board.o

main.o: main.cpp interface.h board.h board.o interface.o
	c++ -c main.cpp

board.o: board.h board.cpp
	c++ -c board.cpp

interface.o: interface.h board.h interface.cpp
	c++ -c interface.cpp

clean:
	rm main.o board.o interface.o