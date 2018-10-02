lca.exe: main.o binaryTree.o input.o
	gcc main.o binaryTree.o input.o -o lca.exe

main.o : main.c binaryTree.c binaryTree.h input.c input.h
	gcc -Wall -c main.c

binaryTree.o : binaryTree.c binaryTree.h
	gcc -Wall -c binaryTree.c

input.o : input.c input.h binaryTree.c binaryTree.h
	gcc -Wall -c input.c

clean :
	rm *.o lca.exe
