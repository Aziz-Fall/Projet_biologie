#include "distance.h"

int main(void)
{   
    //Déclaration des variables.
    FILE *f = open_file("sequences_ADN.data", MODE_READ);
    Distance d = creat_and_init();
    Sequence sequence[NOMBER_SEQUENCES];

    printf("###########################################################\n");

    assign_tab_sequences(sequence, NOMBER_SEQUENCES, f);
    
    for(int i = 0; i < NOMBER_SEQUENCES; i++)
        print_sequence(sequence[i], sequence[i].length);

    printf("###########################################################\n");

    printf("dis: %.1f\n", first_distance(sequence[2], sequence[3], d));

    printf("###########################################################\n");

    close_file(f);
    free_tab_sequence(sequence, NOMBER_SEQUENCES);

    return EXIT_SUCCESS;
}