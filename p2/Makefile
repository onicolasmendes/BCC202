all: pratica.o duende.o
	@gcc pratica.o duende.o -o exe
pratica.o: pratica.c
		@gcc pratica.c -c -Wall
duende.o: duende.c
	@gcc duende.c -c -Wall
run:
	@./exe