#include "distance.h"

//Initialiser et retourner la distance crée.
Distance creat()
{
    //Initialiser une distance
    //Retourner la distance.
}

Distance set_distance(Distance d)
{
    FILE *file = open_file("distance_nucleotide.data", MODE_READ);
    char *string = malloc(sizeof(3));
    double tab[21];
    int i = 0;

    if(is_null(string))
    {
        fprintf(stderr, "Cant set distance.\n");
        return d;
    }

    while(!is_null( string = read_row(file, string, 3)))
        tab[i++] = atof(string);

    for(int i = 0; i < 21; i++)
        printf("%f\n", tab[i]);
    //Remplire les distances des nucléotides
    //Retourne la distance.
    return d;
}

float get_distance_nucleotide(char nucleotide_1, char nucleotide_2)
{
    float d;
    //Récupérer une distance dans le tableau de nuclétide.
    //Retrourne La distance récupérée.
    return d;
}