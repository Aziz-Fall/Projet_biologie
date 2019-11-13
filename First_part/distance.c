#include "distance.h"

//Initialiser et retourner la distance crée.
Distance creatAndInit()
{
    Distance d;
    return set_distance(d);
}

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

double get_distance_nucleotide(char nucleotide_1, char nucleotide_2, Distance d)
{
    int row = hacher(nucleotide_1), col = hacher(nucleotide_2);
    return d.tab[row][col];
}

int hacher(char s) 
{
	int var_hashed = 0;
		var_hashed += (unsigned) (s & 0x0F);  
        var_hashed <<= 1;      
	return ((var_hashed)%5);
}