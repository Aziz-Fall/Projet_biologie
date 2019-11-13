#ifndef __DISTANCE__H__
#define __DISTANCE__H__

#include "fileManager.h"

#define  MODE_READ  "r"
#define NOMBER_NUCLEOTIDES 5


typedef struct Distance
{
    int tab[5][6];  
}Distance;

Distance creat();
Distance set_distance(Distance);
float get_distance_nucleotide(char, char);

#endif