#include "family.h"
#include "list.h"

int main(void)
{  

    //Déclaration des variables.
    FILE *f = open_file("sequences_ADN.data", MODE_READ);

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

    close_file(f);
    free_tab_sequence(sequence, NOMBER_SEQUENCES);
    free_tab_list(dist);
    free_tab_family(tab_f);

    printf("###########################################################\n");

    return EXIT_SUCCESS;
}