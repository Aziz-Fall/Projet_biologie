#include "distance.h"

//Initialiser et retourner la distance crée.
Distance creat_and_init()
{
    Distance d;
    return set_distance(d);
}

//Remplit le tableau de distance.
Distance set_distance(Distance d)
{
    FILE *file = open_file("distance_nucleotide.data", MODE_READ);
    double tab[NOMBER_DISTANCE_NUCLEOTIDE];
    char *string = malloc(sizeof(LENGTH_DISTANCE_NUCLEOTIDE));
    
    if(is_null(string))
    {
        fprintf(stderr, "Cant set distance.\n");
        return d;
    }
    int i = 0;
    
    while((string = read_row(file, string, NOMBER_DISTANCE_NUCLEOTIDE)) != NULL)
    {
        string[2] = '\0';
        tab[i++] = atof(string);
    }
    i = 0;
    for(int row = 0; row < NOMBER_NUCLEOTIDES; row++)
    {
        for (int col = 0; col < NOMBER_NUCLEOTIDES; col++)
            d.tab[row][col] = (tab[i++]*0.1);   
    }

    return d;
}

//Retourne la distance de deux nucléotides.
double get_distance_nucleotide(char nucleotide_1, char nucleotide_2, Distance d)
{
    int row = hacher(nucleotide_1), col = hacher(nucleotide_2);
    return d.tab[row][col];
}

//Hache l'argument et retourne sa valeur.
int hacher(char s) 
{
	int var_hashed = 0;
		var_hashed += (unsigned) (s & 0x0F);  
        var_hashed <<= 1;      
	return ((var_hashed)%5);
}

//Retourne la distance d'édition de deux séquences.D1
double first_distance(Sequence first, Sequence second, Distance d)//D1
{
    double dist_sequence = 0;
    int var = compare_sequence(first, second), max_length = first.length, i = 0;

    if(var < 0)
    {
        max_length = second.length;
        for(i = 0; i < (max_length - 1); i++)
            dist_sequence += get_distance_nucleotide(second.tab_nucleotide[i], first.tab_nucleotide[i], d);
        while(i < (max_length - 1))
            dist_sequence += get_distance_nucleotide(second.tab_nucleotide[i++], BLANC, d);
    }

    for(i = 0; i < (max_length - 1); i++)
        dist_sequence += get_distance_nucleotide(first.tab_nucleotide[i], second.tab_nucleotide[i], d);
     while(i < (max_length - 1))
        dist_sequence += get_distance_nucleotide(first.tab_nucleotide[i++], BLANC, d);

    return dist_sequence;
}