all: main.o nodes.o library.o
	gcc -o testfile main.o nodes.o library.o

main.o: main.c nodes.h
	gcc -c main.c

nodes.o: nodes.c nodes.h
	gcc -c nodes.c

library.o: library.c library.h
	gcc -c library.c

run:
	./testfile

clean:
	rm -rf *.o
	rm -rf testfile.exe
