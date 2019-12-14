#ifndef __ALIGNEMENT__H__
#define __ALIGNEMENT__H__

#include "sequence.h"


#define MAX 20
#define min(a, b)  (((a) < (b)) ? (a) : (b))
//La fréquence d'un caractère.
typedef struct Frequence
{
    char character;
    int freq;
}Freq;

//La position d'un caractère.
typedef struct Position
{
    int position;
    int number_char;
    Freq *tab;
}Pos;

typedef struct Alignement
{
    int number;
    Pos tab[MAX];
}Alignement;

Freq init_freq(char c);
Freq increment_freq(Freq freq);
void print_freq_char(Freq freq);

Pos init_position();
Pos add_position(Pos p, char c);
void free_tab_freq(Pos p);
void print_position(Pos p);

Alignement init_alignement(Sequence a, Sequence b);
Alignement aligne_sequence(Alignement al, Sequence s);
void free_tab_position(Alignement align);
void print_alignement(Alignement align);

#endif