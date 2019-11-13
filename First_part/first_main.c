#include "distance.h"

int main(void)
{
    FILE *file = open_file("distance_nucleotide.data", "r");
    Distance d = creatAndInit();

    for(int row = 0; row < NOMBER_NUCLEOTIDES; row++)
    {
        for (int col = 0; col < NOMBER_NUCLEOTIDES; col++)
            printf("%f\n", d.tab[row][col]);
        printf("#####################\n");
    }

    double distance = get_distance_nucleotide('A', 'A', d);
    printf("distance(A, A) -> %f\n", distance);
    distance = get_distance_nucleotide('A', 'C', d);
    printf("distance(A, A) -> %f\n", distance);
    distance = get_distance_nucleotide('A', 'G', d);
    printf("distance(A, A) -> %f\n", distance);
    distance = get_distance_nucleotide('A', 'T', d);
    printf("distance(A, A) -> %f\n", distance);
    distance = get_distance_nucleotide('A', '_', d);
    printf("distance(A, A) -> %f\n", distance);
    printf("#####################\n");
    close_file(file);

    return EXIT_SUCCESS;
}