#include "distance.h"

int main(void)
{
    FILE *file = open_file("distance_nucleotide.data", "r");
    
    printf("le nombre de ligne du fichier : %d.\n", nomber_row(file));
    
    close_file(file);

    return EXIT_SUCCESS;
}