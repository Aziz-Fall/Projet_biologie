#ifndef __DISTANCE__H__
#define __DISTANCE__H__

#include "fileManager.h"

#define  MODE_READ  "r"
#define NOMBER_NUCLEOTIDES 5
#define LENGTH_DISTANCE_NUCLEOTIDE 3
#define NOMBER_DISTANCE_NUCLEOTIDE 26 



typedef struct Distance
{
    double tab[NOMBER_NUCLEOTIDES][NOMBER_DISTANCE_NUCLEOTIDE];  
}Distance;

Distance creatAndInit();
Distance set_distance(Distance);
int hacher(char s);
double get_distance_nucleotide(char, char, Distance);

#endif