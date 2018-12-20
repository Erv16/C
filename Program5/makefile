FLAG= -g -std=gnu11 -pedantic -Wall
all: program5 clean 
program5: program5.o vector.o stack.o queue.o list.o profile.o
	gcc $(FLAG) program5.o vector.o stack.o queue.o list.o profile.o -o program5   #Linking files to an executable
program5.o: program5.c
	gcc $(FLAG) -c program5.c -o program5.o
vector.o: vector.c
	gcc $(FLAG) -c vector.c -o vector.o
stack.o: stack.c
	gcc $(FLAG) -c stack.c -o stack.o
queue.o: queue.c
	gcc $(FLAG) -c queue.c -o queue.o
list.o: list.c
	gcc $(FLAG) -c list.c -o list.o
profile.o: profile.c
	gcc $(FLAG) -c profile.c -o profile.o
run:program5
	./program5 #execute the program	
memcheck: program5
	valgrind --leak-check=yes --track-origins=yes -v ./program5 #run executable with valgrind
clean: program5
	rm program5.o vector.o stack.o queue.o list.o profile.o program5 #remove object files and executables
submit:
	git add *
	git commit -m "Program 5 from makefile"
	git push
