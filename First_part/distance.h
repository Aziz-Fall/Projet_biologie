#ifndef __DISTANCE__H__
#define __DISTANCE__H__

#include "sequence.h"
#include "list.h"

#define  MODE_READ  "r"
#define BLANC '_'
#define NOMBER_NUCLEOTIDES 5
#define LENGTH_DISTANCE_NUCLEOTIDE 3
#define NOMBER_DISTANCE_NUCLEOTIDE 26 



typedef struct Distance_Nucleotide
{
    double tab[NOMBER_NUCLEOTIDES][NOMBER_NUCLEOTIDES];  
}D_Nucleotide;

typedef struct Distance
{
    List *list;
}Distance;

D_Nucleotide creat_and_init();
D_Nucleotide set_distance(D_Nucleotide);
int hacher(char s);
double get_distance_nucleotide(char, char, D_Nucleotide);
double first_distance(Sequence, Sequence, D_Nucleotide);//D1
Distance distance(Sequence s[],  D_Nucleotide);
void free_tab_list(Distance d);


#endif