all: lista.o main.o
	@gcc lista.o main.o -o programa -Wall
	@rm -rf *.o
main.o: main.c
	@gcc -c main.c -Wall
lista.o: lista.c
	@gcc -c lista.c -Wall
run:
	@./programa
