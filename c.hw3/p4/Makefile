all: main.c numFormat.o numFormat.h
	gcc main.c numFormat.o
numFormat.o: numFormat.c numFormat.h
	gcc -c numFormat.c
clean:
	rm -rf *.o *~ *.out