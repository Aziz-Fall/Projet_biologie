#include "family.h"
#include "list.h"
#include "alignement.h"

int main(int argc, char **argv)
{ 
    //Gestion de l'argument

    if(argc > 2 || argc == 1)
    {
        fprintf(stderr, "No directory!");
        exit(EXIT_FAILURE);
    }

    //Initialisation des structures.
    Tab_File tab_file = init_tab_file();
    Tab_Family tab_f = init_tab_Family();
    Sequence sequence[NOMBER_SEQUENCES];
    D_Nucleotide d = creat_and_init();

    //Traitement des données.
    tab_file = assigne_tab_file(argv[argc - 1]);
    assign_tab_sequences(sequence, NOMBER_SEQUENCES, tab_file);
    Distance dist = distance(sequence, d);
    tab_f = reseach_family(tab_f, dist, sequence);
    tab_f = findSequenceConsensus(tab_f);

    //Affichage des données.
    print_tab_sequences(sequence);  
    print_distance_edition(dist);
    print_tab_family(tab_f);

    //Libération de la mémoire allouer.
    free_tab_family(tab_f);
    free_tab_list(dist);
    free_tab_sequence(sequence, NOMBER_SEQUENCES);
    free_tab_file(tab_file);

    return EXIT_SUCCESS;
}