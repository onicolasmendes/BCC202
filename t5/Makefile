all: main.o ordenacao.o
	@gcc main.o ordenacao.o -o exe -lm -Wall
	@rm -r *.o
main.o: main.c
	@gcc main.c -c -Wall
ordenacao.o: ordenacao.c
	@gcc ordenacao.c -c -Wall
run:
	@./exe
