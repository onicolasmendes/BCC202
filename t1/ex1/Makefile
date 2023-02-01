all: lista.o main.o
	@gcc lista.o main.o -o programa -Wall
	@rm -rf *.o
main.o: main.c
	@gcc main.c -c -Wall
lista.o: lista.c
	@gcc lista.c -c -Wall
run:
	@./programa
