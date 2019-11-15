#ifndef __DISTANCE__H__
#define __DISTANCE__H__

#include "sequence.h"

#define  MODE_READ  "r"
#define BLANC '_'
#define NOMBER_NUCLEOTIDES 5
#define LENGTH_DISTANCE_NUCLEOTIDE 3
#define NOMBER_DISTANCE_NUCLEOTIDE 26 



typedef struct Distance
{
    double tab[NOMBER_NUCLEOTIDES][NOMBER_DISTANCE_NUCLEOTIDE];  
}Distance;

Distance creat_and_init();
Distance set_distance(Distance);
int hacher(char s);
double get_distance_nucleotide(char, char, Distance);
double first_distance(Sequence, Sequence, Distance);//D1

#endif