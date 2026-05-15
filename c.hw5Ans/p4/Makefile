all: main.c Sudoku.o
	gcc main.c Sudoku.o
Sudoku.o: Sudoku.c Sudoku.h
	gcc -c Sudoku.c
clean:
	rm -f *.o *~ a.out