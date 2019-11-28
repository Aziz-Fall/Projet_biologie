#ifndef __FAMILY__H__
#define __FAMILY__H__

#include "sequence.h"
#include "distance.h"

typedef struct Family
{
    int number_element;
    double d_min;
    Sequence *s;

}Family;

Family creat_init_family();
Family add_member(Family f, Sequence s);
Family reseach_family(Distance tab_distance_edition);
void print_family(Family f);
void print_tab_family(Family f);

#endif