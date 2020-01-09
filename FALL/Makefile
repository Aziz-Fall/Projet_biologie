run : main
	valgrind --track-origins=yes ./main sequences_ADN 

main: main.o sequence.o distance.o fileManager.o family.o list.o alignement.o
	gcc -o main *.o -Wall -g 

main.o: main.c distance.h
	gcc -c main.c -g -Wall

sequence.o: sequence.c sequence.h
	gcc -c sequence.c -g -Wall

distance.o: distance.c distance.h
	gcc -c distance.c -g -Wall

alignement.o: alignement.c alignement.h
	gcc -c alignement.c -g -Wall

fileManager.o: fileManager.c fileManager.h const.h
	gcc -c fileManager.c -g -Wall

family.o: family.c family.h
	gcc -c family.c -g -Wall

list.o: list.c list.h
	gcc -c list.c -g -Wall

ZIPNAME=FALL
FILE=finalResult

clean:
	rm -r *.o
	rm -r main
	rm -f $(ZIPNAME).zip
	clear
	ls -l

zip:
	rm -rf $(ZIPNAME)
	rm -f $(ZIPNAME).zip
	mkdir $(ZIPNAME)
	cp *.c $(ZIPNAME)
	cp *.h $(ZIPNAME)
	cp distance_nucleotide.txt $(ZIPNAME)
	cp -r sequences_ADN $(ZIPNAME)
	cp Makefile $(ZIPNAME)
	zip -r $(ZIPNAME).zip $(ZIPNAME)
	rm -rf $(ZIPNAME)
