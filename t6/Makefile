all: principal.o busca.o
	@gcc principal.o busca.o -o exe -Wall
	@rm -r *.o
principal.o: principal.c
	@gcc principal.c -c -Wall
busca.o: busca.c
	@gcc busca.c -c -Wall
run:
	@./exe
