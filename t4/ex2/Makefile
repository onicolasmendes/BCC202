all: ordenacao.o main.o
	@gcc ordenacao.o main.o -o programa -O3 -Wall
	@rm -rf *.o
main.o: main.c
	@gcc -c main.c -Wall
ordenacao.o: ordenacao.c
	@gcc -c ordenacao.c -Wall
run:
	@./programa
