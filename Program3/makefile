FLAG= -g -std=gnu11 -pedantic -Wall
all: program3 clean submit 
program3: program3.o bomb.o
	gcc $(FLAG) program3.o bomb.o hidden.o -o program3 #Linking files to an executable
program3.o: program3.c
	gcc $(FLAG) -c program3.c -o program3.o
bomb.o: bomb.c
	gcc $(FLAG) -c bomb.c -o bomb.o
bscript: program3
	gdb program3 #run executable with gdb
	chmod +x bscript.sh #convert the bash script to an executable
	./bscript.sh phase1.key phase2.key phase3.key phase4.key phase5.key phase6.key bomb_defused.log	
memcheck: program3
	valgrind ./program3 --leak-check=yes -v #run executable with valgrind
clean: program3
	rm program3.o bomb.o program3 #remove object files and executables
	mv keys/* .  #move the files to the current directory
	rm -r keys   #remove the keys directory
submit: program3
	git status
	git add *
	git commit -a -m "Final Commit from the makefile"
	git push
