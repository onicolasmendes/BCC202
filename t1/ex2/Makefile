all: main.o recursividade.o
	@gcc main.o recursividade.o -o programa -Wall
	@rm -rf *.o
main.o: main.c
	@gcc -c main.c  -Wall
recursividade.o: recursividade.c
	@gcc -c recursividade.c  -Wall
run:
	@./programa
