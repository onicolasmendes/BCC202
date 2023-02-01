all: main.o recursividade.o
	@gcc main.o recursividade.o -o programa
	@rm -rf *.o
main.o: main.c
		@gcc main.c -c
recursividade.o: recursividade.c
	@gcc recursividade.c -c
run:
	@./programa
