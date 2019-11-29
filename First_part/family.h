#ifndef __FAMILY__H__
#define __FAMILY__H__

#include "sequence.h"
#include "distance.h"

#define NUMBER_ELEMENT_DEFAULT 3
#define MIN_MEMBER_FAMILY 1

typedef struct Family
{
    int number_element;
    double d_min;
    Sequence *s;

}Family;

typedef struct Tab_Family
{
    int number_family;
    Family *f;

}Tab_Family;


Family creat_family();
Family add_member(Family f, Sequence s);
Tab_Family reseach_family(Tab_Family tab_f, Distance tab_distance_edition, Sequence s[]);
void print_family(Family f);
void print_tab_family(Tab_Family tab_f);
Bool is_empty_family(Family f);
Bool is_empty_tab_family(Tab_Family tab_f);
void free_family(Family f);
double set_distance_min(double d);
Tab_Family init_tab_Family();
Tab_Family add_family(Tab_Family tab_f, Family f);
void free_tab_family(Tab_Family tab_f);

#endif