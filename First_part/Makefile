run : first_main
	./first_main 

first_main: first_main.o sequence.o fileManager.o
	gcc -o first_main *.o -Wall -g 

first_main.o: first_main.c
	gcc -c first_main.c

sequence.o: sequence.c sequence.h
	gcc -c sequence.c

fileManager.o: fileManager.c fileManager.h
	gcc -c fileManager.c
clean:
	rm -r *.o
	rm -r first_main
	clear
	ls -l