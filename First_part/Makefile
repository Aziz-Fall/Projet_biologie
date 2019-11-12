run : first_main
	./first_main

first_main: first_main.o distance.o fileManager.o
	gcc -o first_main *.o -Wall -g 

first_main.o: first_main.c
	gcc -c first_main.c

distance.o: distance.c distance.h
	gcc -c distance.c

fileManager.o: fileManager.c fileManager.h
	gcc -c fileManager.c
clean:
	rm -r *.o
	rm -r first_main
	clear
	ls -l