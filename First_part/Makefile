run : first_main
	 valgrind ./first_main 

first_main: first_main.o sequence.o distance.o fileManager.o family.o list.o
	gcc -o first_main *.o -Wall -g 

first_main.o: first_main.c distance.h
	gcc -c first_main.c -g -Wall

sequence.o: sequence.c sequence.h
	gcc -c sequence.c -g -Wall

distance.o: distance.c distance.h
	gcc -c distance.c -g -Wall

fileManager.o: fileManager.c fileManager.h
	gcc -c fileManager.c -g -Wall

family.o: family.c family.h
	gcc -c family.c -g -Wall

list.o: list.c list.h
	gcc -c list.c -g -Wall
clean:
	rm -r *.o
	rm -r first_main
	clear
	ls -l