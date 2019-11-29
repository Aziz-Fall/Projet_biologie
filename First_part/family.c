#include "family.h"

//Retourne la mémoire réallouer s'il n'y pas d'erreur.
Sequence *reallocate(Family f)
{
    f.s = (Sequence *)realloc(f.s, (f.number_element + 1)*sizeof(Sequence));

    if(is_null(f.s))
    {
        fprintf(stderr, "Cant realloc.\n");
        exit(EXIT_FAILURE);
    }

    return f.s;
}

//Crée une famille.
Family creat_family()
{
    Family f;
    f.s = (Sequence *)malloc(sizeof(Sequence)*NUMBER_ELEMENT_DEFAULT);
    if(is_null(f.s))
    {
        fprintf(stderr, "Cant creat family.\n");
        exit(EXIT_FAILURE);
    }
    f.number_element = 0;
    f.d_min = 0; 

    return f;
}

Bool is_empty_family(Family f)
{
    return ((f.number_element == 0) ? true : false);
}

Bool is_empty_tab_family(Tab_Family tab_f)
{
    return ((tab_f.number_family == 0) ? true : false);
}

//Affiche une famille
void print_family(Family f)
{
    if(is_empty_family(f))
    {
        fprintf(stderr, "Cant print members family.\n");
        return;
    }
    printf("-----------------------------------------------\n");
    printf("|        MEMBERS FAMILY       |     LENTGH    |\n");
    printf("-----------------------------------------------\n");
    for(int i = 0; i < f.number_element; i++)
        printf("|   %20s      |       %d      |\n", f.s[i].tab_nucleotide, f.s[i].length);
    printf("-----------------------------------------------\n");
    printf("| Members                             %2d      |\n", f.number_element);
    printf("| Distance d edition minimale        %2.1f      |\n", f.d_min);
    printf("-----------------------------------------------\n");
}

//Affiche le contenu du tableau de famille.
void print_tab_family(Tab_Family tab_f)
{
    for(int i = 0; i < tab_f.number_family; i++)
        print_family(tab_f.f[i]);
}

//Ajoute un membre dans la famille.
Family add_member(Family f, Sequence s)
{
    if(f.number_element >= NUMBER_ELEMENT_DEFAULT)
    {
        f.s = reallocate(f);
        f.s[f.number_element] = s;
        f.number_element++;
    }
    else
    {
        f.s[f.number_element] = s;
        f.number_element++;
    }
    
    return f;
}

//Initialiser un tableau de famille.
Tab_Family init_tab_Family(Family f)
{
    Tab_Family tab_f;
    tab_f.f = (Family *)malloc(sizeof(Family));
    tab_f.number_family = 0;
    tab_f.f[tab_f.number_family] = f;
    tab_f.number_family++;

    return tab_f;
}

//Ajouter une famille dans le tableau.
Tab_Family add_family(Tab_Family tab_f, Family f)
{
    tab_f.f = (Family *)realloc(tab_f.f, (tab_f.number_family + 1)*sizeof(Family));
    if(is_null(tab_f.f))
    {
        fprintf(stderr, "Cant add family in the array.\n");
        exit(EXIT_FAILURE);
    }

    tab_f.f[tab_f.number_family] = f;
    tab_f.number_family++;

    return tab_f;
}

//Assigne la distance d'édition minimale.
double set_distance_min(double d)
{
    return d;
}

//Libére la mémoire allouer pour la famille.
void free_family(Family f)
{
    if(is_empty_family(f))
        return;
    
    free(f.s);
}

//Libére la mémoire allouer pour le tableau de famille;
void free_tab_family(Tab_Family tab_f)
{
    if(is_empty_tab_family(tab_f))
        return;
    for(int i = 0; i < tab_f.number_family; i++)
        free_family(tab_f.f[i]);
}