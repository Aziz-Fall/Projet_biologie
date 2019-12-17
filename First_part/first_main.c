#include "family.h"
#include "list.h"
#include "alignement.h"

int main(int argc, char **argv)
{ 
    printf("###########################################################\n");
    
    if(argc > 2 || argc == 1)
    {
        fprintf(stderr, "No directory!");
        exit(EXIT_FAILURE);
    }

    Tab_File tab_file = init_tab_file();
    Sequence sequence[NOMBER_SEQUENCES];
    D_Nucleotide d = creat_and_init();

    tab_file = assigne_tab_file(argv[argc - 1]);
    assign_tab_sequences(sequence, NOMBER_SEQUENCES, tab_file);
    
    Alignement al = init_alignement(sequence[2], sequence[6]);
    print_alignement(al);
    printf("###########################################################\n");
    al = aligne_sequence(al, sequence[4]);
    print_alignement(al);
    printf("###########################################################\n");
    Sequence sequenceConsensus = get_sequence_consensus(al);
    print_sequence(sequenceConsensus, sequenceConsensus.length);
    printf("###########################################################\n");
    free(sequenceConsensus.tab_nucleotide);
    free_tab_position(al);
    free_tab_file(tab_file);
    free_tab_sequence(sequence, NOMBER_SEQUENCES);
    /*printf("###########################################################\n");
    
    for(int i = 0; i < NOMBER_SEQUENCES; i++)
    {
        printf("%2d ", i);
        print_sequence(sequence[i], sequence[i].length);
    }

    printf("###########################################################\n");
    
    Tab_Family tab_f = init_tab_Family();
    Distance dist = distance(sequence, d);
    tab_f = reseach_family(tab_f, dist, sequence);
    print_tab_family(tab_f);

    printf("###########################################################\n");
    //Libération de la mémoire allouer.
    free_tab_family(tab_f);
    free_tab_list(dist);
    free_tab_sequence(sequence, NOMBER_SEQUENCES);
    free_tab_file(tab_file);

    printf("###########################################################\n");*/

    return EXIT_SUCCESS;
}