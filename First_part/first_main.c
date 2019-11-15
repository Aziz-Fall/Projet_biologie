#include "sequence.h"

int main(void)
{
    FILE *f = open_file("sequences_ADN.data", MODE_READ);
    Sequence sequence[NOMBER_SEQUENCES];
    printf("###########################################################\n");
    assign_tab_sequences(sequence, NOMBER_SEQUENCES, f);
    
    for(int i = 0; i < NOMBER_SEQUENCES; i++)
        print_sequence(sequence[i], sequence[i].length);
    printf("###########################################################\n");
    close_file(f);
    free_tab_sequence(sequence, NOMBER_SEQUENCES);
    return EXIT_SUCCESS;
}