all: f91.o main.o
	@gcc f91.o main.o -o programa -Wall
	@rm -rf *.o
main.o: main.c
	@gcc -c main.c -Wall
f91.o: f91.c
	@gcc -c f91.c -Wall
run:
	@./programa
