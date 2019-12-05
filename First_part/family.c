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
    f.s = NULL;//(Sequence *)malloc(sizeof(Sequence)*NUMBER_ELEMENT_DEFAULT);
    /*if(is_null(f.s))
    {
        fprintf(stderr, "Cant creat family.\n");
        exit(EXIT_FAILURE);
    }*/
    f.number_element = 0;
    f.d_min = 0; 

    return f;
}
//Vérifie si la famile est vide si oui retoune true sinon false.
Bool is_empty_family(Family f)
{
    return ((f.number_element == 0) ? true : false);
}

//Vérifie si le tableau de famille est vide si oui retoune true sinon false.
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
        print_sequence(f.s[i], f.s[i].length);
        //printf("|   %20s      |       %d      |\n", f.s[i].tab_nucleotide, f.s[i].length);
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
    f.s = (Sequence *)realloc(f.s, (f.number_element + 1)*sizeof(Sequence));

    if(is_null(f.s))
    {
        fprintf(stderr, "Cant realloc.\n");
        exit(EXIT_FAILURE);
    }

    f.s[f.number_element] = s;
    f.number_element++;
    
    return f;
}

//Initialiser un tableau de famille.
Tab_Family init_tab_Family()
{
    Tab_Family tab_f;
    tab_f.f = NULL;
    tab_f.number_family = 0;

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

//Recherche une famille et retourne les familles trouvées dans un tableau. 
Tab_Family reseach_family(Tab_Family tab_f, Distance tab_distance_edition, Sequence s[])
{
    for(int i = 0; i < NOMBER_SEQUENCES; i++)
    {
        int count = count_distance_min(tab_distance_edition.list[i]);
        double min = d_edition_min(tab_distance_edition.list[i]);

        if(count > MIN_MEMBER_FAMILY)
        {
            if(min < 10)
            {
                Family f = creat_family();
                f = add_member(f, s[tab_distance_edition.list[i]->index]);
                f.d_min = set_distance_min(min);

                List tmp = tab_distance_edition.list[i];

                while(tmp->d_edition == min)
                {
                    f = add_member(f, s[tmp->index]);
                    tmp = tmp->next;
                } 

                tab_f = add_family(tab_f, f);
            }
        }
    }
    return tab_f;
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
    
    free(tab_f.f);
}