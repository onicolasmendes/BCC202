all: pratica.o lista.o
	@gcc pratica.o lista.o -o programa
	@rm -rf *.o
pratica.o: pratica.c
		@gcc pratica.c -c
lista.o: lista.c
	@gcc lista.c -c
run:
	@./programa
