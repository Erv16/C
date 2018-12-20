FLAG= -g -std=gnu11 -pedantic -Wall
all: program4 clean submit 
program4: program4.o tournament.o
	gcc $(FLAG) program4.o tournament.o -o program4 #Linking files to an executable
program4.o: program4.c
	gcc $(FLAG) -c program4.c -o program4.o
tournament.o: tournament.c
	gcc $(FLAG) -c tournament.c -o tournament.o
run:program4
	./program4 #execute the program	
memcheck: program4
	valgrind --leak-check=yes -v ./program4 #run executable with valgrind
clean: program4
	rm program4.o tournament.o program4 #remove object files and executables
submit: program4
	git status
	git add *
	git commit -a -m "Final Commit from the makefile"
	git push
