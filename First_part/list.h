#ifndef __LIST__H__
#define __LIST__H__

#include "fileManager.h"

typedef struct Element
{
    int index;
    double   d_edition;
    struct Element *next;
}Element, *List;

List creat_list();
void print_list(List l);
List insert(List l, int index, int d_edition);
List delete_element(List l);
void free_list(List l);
double d_edition_min(List l);

#endif