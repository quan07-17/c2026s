all: main.c circle.o
	gcc main.c circle.o -lm
circle.o: circle.c point.h
	gcc -c circle.c
clean:
	rm -rf *.o *~ *.out