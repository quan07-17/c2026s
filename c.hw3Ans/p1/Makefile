all: main.c reverse.o reverse.h
	gcc main.c reverse.o
reverse.o: reverse.c reverse.h
	gcc -c reverse.c
clean:
	rm -rf *.o *~ *.out
