FLAG= -g -std=gnu11 -pedantic -Wall
all: program6 clean 
program6: program6.o bst.o
	gcc $(FLAG) program6.o bst.o -o program6   #Linking files to an executable
program6.o: program6.c
	gcc $(FLAG) -c program6.c -o program6.o
bst.o: bst.c
	gcc $(FLAG) -c bst.c -o bst.o
run:program6
	./program6 #execute the program	
memcheck: program6
	valgrind --leak-check=yes --track-origins=yes -v ./program6 #run executable with valgrind
clean: program6
	rm program6.o bst.o program6 #remove object files and executables

