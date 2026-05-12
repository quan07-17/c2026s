all: main.c chess.o
	gcc main.c chess.o
chess.o: chess.c
	gcc -c chess.c
clean:
	rm -rf *.o *~ *.out