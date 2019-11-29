#include "family.h"
#include "list.h"

int main(void)
{  

    //Déclaration des variables.
    FILE *f = open_file("sequences_ADN.data", MODE_READ);

    //D_Nucleotide d = creat_and_init();
    Sequence sequence[NOMBER_SEQUENCES];

    printf("###########################################################\n");

    assign_tab_sequences(sequence, NOMBER_SEQUENCES, f);
    
    for(int i = 0; i < NOMBER_SEQUENCES; i++)
    {
        printf("%2d ", i);
        print_sequence(sequence[i], sequence[i].length);
    }

    printf("###########################################################\n");

    Family family_1 = creat_family();
    family_1 = add_member(family_1, sequence[0]);
    family_1 = add_member(family_1, sequence[1]);
    family_1 = add_member(family_1, sequence[8]);
    family_1 = add_member(family_1, sequence[3]);
    family_1 = add_member(family_1, sequence[3]);
    family_1.d_min = set_distance_min(4.5);

    Family family_2 = creat_family();
    family_2 = add_member(family_2, sequence[0]);
    family_2 = add_member(family_2, sequence[1]);
    family_2 = add_member(family_2, sequence[8]);
    family_2 = add_member(family_2, sequence[3]);
    family_2 = add_member(family_2, sequence[3]);
    family_2.d_min = set_distance_min(4.5);
    Tab_Family tab_f = init_tab_Family(family_1);
    tab_f = add_family(tab_f, family_2);
    print_tab_family(tab_f);
    
    printf("###########################################################\n");
    /*
    printf("dis: %.1f\n", first_distance(sequence[16], sequence[13], d));
    printf("dis: %.1f\n", first_distance(sequence[15], sequence[13], d));
    printf("dis: %.1f\n", first_distance(sequence[12], sequence[13], d));
    printf("dis: %.1f\n", first_distance(sequence[4], sequence[13], d));

    printf("###########################################################\n");

    Distance dist = distance(sequence, d);
    print_list(dist.list[17]);

    printf("###########################################################\n");
    */
    close_file(f);
    free_tab_sequence(sequence, NOMBER_SEQUENCES);
    //free_tab_list(dist);

    printf("###########################################################\n");

    free_tab_family(tab_f);

    return EXIT_SUCCESS;
}