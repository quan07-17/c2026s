all: main.c cardValid.o
	gcc main.c cardValid.o
cardValid.o: cardValid.c cardValid.h
	gcc -c cardValid.c
clean:
	rm -rf *.o *~ *.out