#include "alignement.h"

//Crée et initialise la fréquence d'un caratère.
Freq init_freq(char c)
{
    Freq f;
    f.freq = 1;
    f.character = c;
    return f;
}

//Incrémente la fréquence du caractére.
Freq increment_freq(Freq freq)
{
    ++(freq.freq);
    return freq;
}

//Afficher le contenu de la fréquence.
void print_freq_char(Freq freq)
{
    printf("char : %c ---> freq: %2d\n", freq.character, freq.freq);
}

//Initialiser la position des caractéres et retourne une position .
Pos init_position()
{
    Pos p;
    p.number_char = 0;
    p.tab = NULL;

    return p;
}

//Ajouter un caractère et sa position.
Pos add_position(Pos p, char c)
{

    for(int i = 0; i < p.number_char; i++)
        if(p.tab[i].character == c)
        {
                p.tab[i] = increment_freq(p.tab[i]);
                return p;
        }

    p.tab = (Freq *)realloc(p.tab, sizeof(Freq)*(p.number_char + 1));
    p.tab[p.number_char] = init_freq(c);
    p.number_char++;
    return p;   
}

//Libére la mémoire allouer pour le tableau de fréquence.
void free_tab_freq(Pos p)
{
    error(p.tab, "Cant print free tab frequence");
    free(p.tab);
}

//Afficher les caractéres d'une position 
void print_position(Pos p)
{
    error(p.tab, "Cant print position");
    for(int i = 0; i < p.number_char; i++)
        print_freq_char(p.tab[i]);
    printf("\n");
}

//Initialise un alignement avec deux  séquences.
Alignement init_alignement(Sequence a, Sequence b)
{
    Alignement al;
    al.number = 0;
    for(int i = 0; i < a.length; i++)
    {
        Pos pos = init_position();
        pos = add_position(pos, a.tab_nucleotide[i]);
        pos = add_position(pos, b.tab_nucleotide[i]);
        al.tab[al.number++] = pos;
    }
    return al;
}

//Ajouter une séquences dans l'alignement;
Alignement aligne_sequence(Alignement al, Sequence s)
{
    int min = min(al.number, s.length);
    for(int i = 0; i < min; i++)
        al.tab[i] = add_position(al.tab[i], s.tab_nucleotide[i]);

    return al;
}

//Libére la mémoire allouer pour stocker les fréquences de caractères.
void free_tab_position(Alignement align)
{
    for (int i = 0; i < align.number; i++)
        free_tab_freq(align.tab[i]);  
}
void print_alignement(Alignement align)
{
    if(align.number == 0)
    {
        fprintf(stderr, "Cant print alignement:(\n");
        return;
    }
    for(int i = 0; i < align.number; i++)
        print_position(align.tab[i]);
}