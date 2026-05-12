all: main.c search.o
	gcc main.c search.o
trim.o: search.c
	gcc -c search.c
clean:
	rm -rf *.o *~ *.out