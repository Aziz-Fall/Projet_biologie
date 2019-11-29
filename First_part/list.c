#include "list.h"

//Creé , initiailsé un élement et le retourne.
Element *creat_element(int index, double d_edition)
{
    Element *e = malloc(sizeof(Element));
    if(is_null(e))
    {
        fprintf(stderr, "Cant creat element\n");
        exit(EXIT_FAILURE);
    }
    e->d_edition = d_edition,
    e->index = index;
    e->next = NULL;

    return e;
}

//Crée une liste vide.
List creat_list()
{
    return NULL;
}

//Affiche le contenu de la liste.
void print_list(List l)
{
  if(is_null(l))
      return;

  printf("e: index = %2d - d_edition = %2.1f\n", l->index, l->d_edition);

  print_list(l->next);

}

//Insérer un élement dans la liste.
List insert(List l, int index, int d_edition)
{
    Element *e = creat_element(index, d_edition);

    if(is_null(l) || l->d_edition >= d_edition)
    {
        e->next = l;
        return e;
    }

    l->next = insert(l->next, index, d_edition);

    return l;
}

//Supprime un élement dans la liste.
List delete_element(List l)
{
    Element *this = malloc(sizeof(Element));

    if(is_null(this))
    {
        fprintf(stderr, "Cant delete element\n");
        return l;
    }
    this = l;
    l = l->next;
    free(this);

    return l;
}

//Libére la mémoire allouer pour la liste.
void free_list(List l)
{
    Element *this = malloc(sizeof(Element));

    if(is_null(this))
        return;
    while(!is_null(l))
    {
        this = l;
        l = l->next;
        free(this);
    }
}

//Retourne la distance d'édition minimale.
double d_edition_min(List l)
{
    return l->d_edition;
}

//Retourne le nombre fois qu'on un distance min dans la list.
int count_distance_min(List l)
{
    int var = 0;
    if(is_null(l))
    {
        fprintf(stderr, "Cant count distance min.\n");
        return var;
    }

    double min = d_edition_min(l);

    while(!is_null(l))
    {
        if(l->d_edition == min)
        {
            ++var;
            l = l->next;
        }
        else 
            break;
    }
    
    return var;
}