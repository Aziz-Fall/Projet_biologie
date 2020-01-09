// ############################################
//                  SOMMAIRE
// ############################################
//
// 1. TYPES .......................... ligne  18
// 2. GESTION D'ALIGNEMENT ........... ligne  44
// 3. AFFICHAGE ...................... ligne  58
// 4. LIBERATION DE LA MÉMOIRE ....... ligne  65
//
// #############################################

#ifndef __ALIGNEMENT__H__
#define __ALIGNEMENT__H__

#include "sequence.h"

// #####################################
// 1. TYPES
// #####################################

    //Définition du type Freq.
    typedef struct Frequence
    {
        char character;
        int freq;
    }Freq;

    //Définition du type Position.
    typedef struct Position
    {
        int position;
        int number_char;
        Freq *tab;
    }Pos;

    //Définition du type Alignement.
    typedef struct Alignement
    {
        int number;
        Pos tab[MAX];
    }Alignement;

// #####################################
// 2. GESTION D'ALIGNEMENT
// #####################################

    //Initialise le type Alignement et le retourne
    Alignement init_alignement(Sequence a, Sequence b);

    //Aligner une séquence et retourne le type Alignement.
    Alignement aligne_sequence(Alignement al, Sequence s);

    //Retourner la séquence consensus.
    Sequence get_sequence_consensus(Alignement align);


// #####################################
// 3. AFFICHAGE
// #####################################
    
    //Afficher l'alignement.
    void print_alignement(Alignement align);

// #####################################
// 4. LIBERATION DE LA MEMOIRE
// #####################################

    //Libérer la mémoire allouer.
    void free_tab_position(Alignement align);


#endif