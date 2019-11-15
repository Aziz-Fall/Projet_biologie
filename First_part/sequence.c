#include "sequence.h"

//Crée et retourne une séquence non vide.
Sequence creat_init_sequence(char *string)
{
    Sequence s;

    int size = (int)strlen(string);

    s.tab_nucleotide = malloc(sizeof(char*)*size);

    if(size == 0 || is_null(s.tab_nucleotide))
    {
        fprintf(stderr, "Cant creat sequence.\n");
        exit(EXIT_FAILURE);
    }

    s.length = size;
    for(int i = 0; i < s.length; i++)
        s.tab_nucleotide[i] = string[i];

    s.tab_nucleotide[(s.length - 1)] = CHAR_END_STRING;

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
int compare_sequence(Sequence first, Sequence second);

//Affiche la séquence passée en argument.
void print_sequence(Sequence s, int nb_nucleotides)
{
    for(int i = 0; i < nb_nucleotides; i++)
        printf("%c", s.tab_nucleotide[i]);
    printf("    L = %d\n", nb_nucleotides);
}

void free_tab_sequence(Sequence s[], int nb_sequence)
{
    for(int i; i < nb_sequence; i++)
        free(s[i].tab_nucleotide);
}