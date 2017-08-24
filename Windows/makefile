GameOfLife: main.o gol.o
	gcc -o GameOfLife main.o gol.o
main.o: main.c
	gcc -c main.c
gol.o: gol.c gol.h
	gcc -c gol.c
clean:
	rm main.o gol.o
