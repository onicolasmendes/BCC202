all: ordenacao.o principal.o
	@gcc ordenacao.o principal.o -o programa -Wall
	@rm -rf *.o
principal.o: principal.c
	@gcc -c principal.c -Wall
ordenacao.o: ordenacao.c
	@gcc -c ordenacao.c -Wall
run:
	@./programa
