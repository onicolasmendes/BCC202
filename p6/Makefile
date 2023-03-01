all: pratica.o ordenacao.o
	@gcc pratica.o ordenacao.o -o exe -O3 -Wall
pratica.o: pratica.c
		@gcc pratica.c -c -Wall
ordenacao.o: ordenacao.c
	@gcc ordenacao.c -c -Wall
run:
	@./exe
