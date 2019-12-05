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
List insert(List l, int index, double d_edition)
{
    List tmp = l;
    Element *e = creat_element(index, d_edition);

    if(is_null(l))
        return e;

    //Insertion au début de la liste.
    if(l->d_edition >= d_edition)
    {
        e->next = l;
        return e;
    }
    //Insertion au milieu de la liste.
    while((l->d_edition <= d_edition) && !is_null(l->next))
    {
        if(l->next->d_edition >= d_edition)
        {
            e->next = l->next;
            l->next = e;
            return tmp;
        }
        l = l->next;
    }

    //Insertion au milieu ou fin de la liste.
    if(is_null(l->next) && l->d_edition < d_edition)
        l->next = e;

    return tmp;
}

//Supprime un élement dans la liste.
List delete_element(List l)
{
    Element *this;

    this = l;
    l = l->next;

    free(this);

    return l;
}

//Libére la mémoire allouer pour la liste.
void free_list(List l)
{
    Element *this;

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
    List tmp = l;
    if(is_null(l))
    {
        fprintf(stderr, "Cant count distance min.\n");
        return var;
    }

    double min = d_edition_min(tmp);

    while(!is_null(tmp))
    {
        if(tmp->d_edition == min)
        {
            ++var;
            tmp = tmp->next;
        }
        else 
            break;
    }
    
    return var;
}