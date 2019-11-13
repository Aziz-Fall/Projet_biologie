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

    double distance = get_distance_nucleotide('_', '_', d);
    printf("distance(_, _) -> %f\n", distance);
    distance = get_distance_nucleotide('_', 'C', d);
    printf("distance(_, C) -> %f\n", distance);
    distance = get_distance_nucleotide('_', 'A', d);
    printf("distance(_, A) -> %f\n", distance);
    distance = get_distance_nucleotide('_', 'G', d);
    printf("distance(_, G) -> %f\n", distance);
    distance = get_distance_nucleotide('_', 'T', d);
    printf("distance(_, T) -> %f\n", distance);
    printf("#####################\n");
    distance = get_distance_nucleotide('C', '_', d);
    printf("distance(C, _) -> %f\n", distance);
    distance = get_distance_nucleotide('C', 'C', d);
    printf("distance(C, C) -> %f\n", distance);
    distance = get_distance_nucleotide('C', 'A', d);
    printf("distance(C, A) -> %f\n", distance);
    distance = get_distance_nucleotide('C', 'G', d);
    printf("distance(C, G) -> %f\n", distance);
    distance = get_distance_nucleotide('C', 'T', d);
    printf("distance(C, T) -> %f\n", distance);
    printf("#####################\n");
    distance = get_distance_nucleotide('A', '_', d);
    printf("distance(A, _) -> %f\n", distance);
    distance = get_distance_nucleotide('A', 'C', d);
    printf("distance(A, C) -> %f\n", distance);
    distance = get_distance_nucleotide('A', 'A', d);
    printf("distance(A, A) -> %f\n", distance);
    distance = get_distance_nucleotide('A', 'G', d);
    printf("distance(A, G) -> %f\n", distance);
    distance = get_distance_nucleotide('A', 'T', d);
    printf("distance(A, T) -> %f\n", distance);
    printf("#####################\n");
    distance = get_distance_nucleotide('T', '_', d);
    printf("distance(T, _) -> %f\n", distance);
    distance = get_distance_nucleotide('T', 'C', d);
    printf("distance(T, C) -> %f\n", distance);
    distance = get_distance_nucleotide('T', 'A', d);
    printf("distance(T, A) -> %f\n", distance);
    distance = get_distance_nucleotide('T', 'G', d);
    printf("distance(T, G) -> %f\n", distance);
    distance = get_distance_nucleotide('T', 'T', d);
    printf("distance(T, T) -> %f\n", distance);
    printf("#####################\n");
    distance = get_distance_nucleotide('G', '_', d);
    printf("distance(G, _) -> %f\n", distance);
    distance = get_distance_nucleotide('G', 'C', d);
    printf("distance(G, C) -> %f\n", distance);
    distance = get_distance_nucleotide('G', 'A', d);
    printf("distance(G, A) -> %f\n", distance);
    distance = get_distance_nucleotide('G', 'G', d);
    printf("distance(G, G) -> %f\n", distance);
    distance = get_distance_nucleotide('G', 'T', d);
    printf("distance(G, T) -> %f\n", distance);
    printf("#####################\n");
    close_file(file);

    return EXIT_SUCCESS;
}