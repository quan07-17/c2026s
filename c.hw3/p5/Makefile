all: main.c trim.o
	gcc main.c trim.o
trim.o: trim.c
	gcc -c trim.c
clean:
	rm -rf *.o *~ *.out