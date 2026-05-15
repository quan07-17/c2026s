all: main.c replace.o
	gcc main.c replace.o
replace.o: replace.c
	gcc -c replace.c
clean:
	rm -f *.*~ a.* *.o *.o~