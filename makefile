lca.exe: main.o binaryTree.o input.o list.o dag.o
	gcc main.o binaryTree.o input.o list.o dag.o -o lca.exe

main.o : main.c binaryTree.h input.h
	gcc -Wall -c main.c

binaryTree.o : binaryTree.c binaryTree.h
	gcc -Wall -c binaryTree.c

input.o : input.c input.h binaryTree.h
	gcc -Wall -c input.c

list.o : list.c list.h
	gcc -Wall -c list.c

dag.o : dag.c dag.h list.h
	gcc -Wall -c dag.c

clean :
	rm *.o lca.exe
