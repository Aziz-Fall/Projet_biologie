#ifndef __DISTANCE__H__
#define __DISTANCE__H__

#include "fileManager.h"

#define  MODE_READ  "r"
#define NOMBER_NUCLEOTIDES 5


typedef struct Pair_sequence
{
    char nucleotide;
    float distance_nucleotide[NOMBER_NUCLEOTIDES];
}Pair_sequence;

typedef struct Distance
{
    Pair_sequence *tab[NOMBER_NUCLEOTIDES];  
}Distance;

Distance creat();
Distance set_distance(Distance);
float get_distance_nucleotide(char, char);

#endif