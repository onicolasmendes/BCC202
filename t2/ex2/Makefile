all: r9.o main.o
	@gcc r9.o main.o -o programa -Wall
	@rm -rf *.o
main.o: main.c
	@gcc -c main.c -Wall
r9.o: r9.c
	@gcc -c r9.c -Wall
run:
	@./programa
