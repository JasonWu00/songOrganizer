all: main.o nodes.o
	gcc -o testfile main.o nodes.o

main.o: main.c nodes.h
	gcc -c main.c

nodes.o: nodes.c nodes.h
	gcc -c nodes.c

run:
	./testfile

clean:
	rm -rf *.o
	rm -rf testfile.exe
