#include "distance.h"

int main(void)
{
    FILE *file = open_file("distance_nucleotide.data", "r");
    Distance d;
    set_distance(d);
    
    close_file(file);

    return EXIT_SUCCESS;
}