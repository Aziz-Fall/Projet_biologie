#include "distance.h"
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
        print_sequence(sequence[i], sequence[i].length);

    printf("###########################################################\n");

    printf("dis: %.1f\n", first_distance(sequence[17], sequence[9], d));

    printf("###########################################################\n");

    Distance dist = distance(sequence, d);
    print_list(dist.list[19]);

    printf("###########################################################\n");

    close_file(f);
    free_tab_sequence(sequence, NOMBER_SEQUENCES);

    return EXIT_SUCCESS;
}