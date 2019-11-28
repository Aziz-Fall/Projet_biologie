#include "family.h"
#include "list.h"

int main(void)
{  

    //Déclaration des variables.
    FILE *f = open_file("sequences_ADN.data", MODE_READ);

    D_Nucleotide d = creat_and_init();
    Sequence sequence[NOMBER_SEQUENCES];

    printf("###########################################################\n");


    printf("%ld\n", sizeof(Sequence));

    printf("###########################################################\n");

    assign_tab_sequences(sequence, NOMBER_SEQUENCES, f);
    
    for(int i = 0; i < NOMBER_SEQUENCES; i++)
    {
        printf("%2d ", i);
        print_sequence(sequence[i], sequence[i].length);
    }

    Family family = creat_init_family(sequence[0], 2);
    family = add_member(family, sequence[4]);
    print_family(family);
    /*
    printf("###########################################################\n");

    printf("dis: %.1f\n", first_distance(sequence[16], sequence[13], d));
    printf("dis: %.1f\n", first_distance(sequence[15], sequence[13], d));
    printf("dis: %.1f\n", first_distance(sequence[12], sequence[13], d));
    printf("dis: %.1f\n", first_distance(sequence[4], sequence[13], d));

    printf("###########################################################\n");

    Distance dist = distance(sequence, d);
    print_list(dist.list[17]);

    printf("###########################################################\n");

    close_file(f);
    free_tab_sequence(sequence, NOMBER_SEQUENCES);
    free_tab_list(dist);

    printf("###########################################################\n");*/

    free(family.s);

    return EXIT_SUCCESS;
}