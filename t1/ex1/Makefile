all: lista.o main.o
	@gcc lista.o main.o -o programa
	@rm -rf *.o
main.o: main.c
		@gcc main.c -c
lista.o: lista.c
	@gcc lista.c -c
run:
	@./programa
