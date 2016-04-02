try :test.o Sudoku.o
	g++ -o try test.o Sudoku.o

test.o : Sudoku.h test.cpp
	g++ -c test.cpp

Sudoku.o: Sudoku.h Sudoku.cpp
	g++ -c Sudoku.cpp

clean:
	rm try *.o
