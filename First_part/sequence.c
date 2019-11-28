#include "sequence.h"

//Crée et retourne une séquence non vide.
Sequence creat_init_sequence(char *string)
{
    Sequence s;

    int size = (int)strlen(string) - 1;

    s.tab_nucleotide = malloc(sizeof(char*)*size);

    if(size == 0 || is_null(s.tab_nucleotide))
    {
        fprintf(stderr, "Cant creat sequence.\n");
        exit(EXIT_FAILURE);
    }

    s.length = size;

    for(int i = 0; i < s.length; i++)
        s.tab_nucleotide[i] = string[i];

    return s;
}

//Assign un tableau de sequence.
void assign_tab_sequences(Sequence s[], int nb_element, FILE *f)
{
    for(int i = 0; i < nb_element; i++)
    {
        char *string = malloc(sizeof(char*)*MAX_LENGTH);

        if(is_null(string))
        {
            fprintf(stderr, "Cant assign tab seqences.\n");
            return;
        }  

        string = read_row(f, string, MAX_LENGTH);

        if(is_null(string))
        {
            fprintf(stderr, "No sequence :File is empty.\n");
            return;
        }

        s[i] = creat_init_sequence(string);

        free(string);
    }
}

//Retourn la différence de tailles des deux séquences.
int compare_sequence(Sequence first, Sequence second)
{
    int difference = (first.length - second.length), var = ARE_EQUALS;
    if(difference > 0)
        var = LARGER_SIZE;
    else if(difference < 0)
        var = LOWER_SIZE;
    
    return var;
}

//Affiche la séquence passée en argument.
void print_sequence(Sequence s, int nb_nucleotides)
{   
    for(int i = 0; i < nb_nucleotides; i++)
        printf("%c", s.tab_nucleotide[i]);
    printf("       L = %2d\n", nb_nucleotides);

}

//Libére la mémoire allouer.
void free_tab_sequence(Sequence s[], int nb_sequence)
{
    for(int i = 0; i < nb_sequence; i++)
        free(s[i].tab_nucleotide);
}