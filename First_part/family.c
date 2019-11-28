#include "family.h"

//Créer une famille.
Family creat_init_family(Sequence s, int d_min)
{
    Family f;

    f.number_element = 1;
    f.d_min = d_min;
    f.s = malloc(sizeof(Sequence));

    if(is_null(f.s))
    {
        fprintf(stderr, "Cant creat Family.\n");
        exit(EXIT_FAILURE);
    }

    f.s[f.number_element  - 1] = s;
    
    return f;
}

//Ajouter une séquence dans la famille.
Family add_member(Family f, Sequence s)
{
    f.s = realloc(f.s, (f.number_element + 1));

    if(is_null(f.s))
    {
        fprintf(stderr, "Cant add member in the family\n");
        return f;
    }

    f.s[f.number_element] = s;
    f.number_element++;
    
    return f;
}

//Recherche des familles.
//Family reseach_family(Distance tab_distance_edition)

//Affiche la famille.
void print_family(Family f)
{
    printf("-------------------------------------------------\n");
    printf("|           FAMILY            |       LENGHT    |\n");
    printf("-------------------------------------------------\n");
    for(int i = 0; i < f.number_element; i++)
        print_sequence(f.s[i], f.s[i].length);
    printf("-------------------------------------------------\n");
    printf("|distance min = %2.1f\n                    \n", f.d_min);
    printf("-------------------------------------------------\n"); 
}

//Affiche un tableau de famille.
void print_tab_family(Family f)
{

}
