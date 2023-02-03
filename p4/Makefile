all: pratica.o lista.o
	@gcc pratica.o lista.o -o programa -Wall
	@rm -rf *.o
pratica.o: pratica.c
	@gcc -c pratica.c -Wall
lista.o: lista.c
	@gcc -c lista.c -Wall
run:
	@./programa
