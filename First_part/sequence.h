#ifndef __SEQUENCE__H__
#define __SEQUENCE__H__

#include "fileManager.h"

#define ARE_EQUALS 0
#define LARGER_SIZE 1
#define LOWER_SIZE -1
#define MAX_LENGTH 30
#define NOMBER_SEQUENCES 20
#define CHAR_END_STRING '\0'
 
typedef struct Sequence
{
    int length;
    char *tab_nucleotide;

}Sequence;

Sequence creat_init_sequence(char*);
void assign_tab_sequences(Sequence s[], int nb_element, Tab_File tab_file);
int compare_sequence(Sequence first, Sequence second);
void print_sequence(Sequence s, int nb_nucleotides);
void free_tab_sequence(Sequence s[], int nb_sequence);

#endif