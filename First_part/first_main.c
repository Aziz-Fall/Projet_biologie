#include "family.h"
#include "list.h"

int main(int argc, char **argv)
{  
    printf("###########################################################\n");

    if(argc > 2 || argc == 1)
    {
        fprintf(stderr, "No directory!");
        exit(EXIT_FAILURE);
    }
    
    printf("argc: %d\n", argc);
    printf("directory: %s\n", argv[argc - 1]);

    Tab_File tab_f = init_tab_file();
    tab_f = assigne_tab_file(argv[argc - 1]);
    printf("file: %ld\n", sizeof(File));
    printf("###########################################################\n");

    for(int i = 0; i < tab_f.number_file; i++)
        printf("file[%2d] = %s\n",i , tab_f.file[i].name);

    printf("###########################################################\n");

    free_tab_file(tab_f);
    
    /*//Déclaration des variables.
    FILE *f = open_file("sequences_ADN.txt", MODE_READ);

    D_Nucleotide d = creat_and_init();

    Sequence sequence[NOMBER_SEQUENCES];

    printf("###########################################################\n");

    assign_tab_sequences(sequence, NOMBER_SEQUENCES, f);
    
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

    free_tab_family(tab_f);
    free_tab_list(dist);
    free_tab_sequence(sequence, NOMBER_SEQUENCES);
    close_file(f);
    
    

    //printf("###########################################################\n");*/

    return EXIT_SUCCESS;
}