all: main.c login.o
	gcc main.c login.o
login.o: login.c login.h
	gcc -c login.c
clean:
	rm -rf *.o *~ *.out