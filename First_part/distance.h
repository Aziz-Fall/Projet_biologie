
// ############################################
//                   SOMMAIRE
// ############################################
//
// 1. TYPES .......................... ligne  20
// 2. GESTION D'UNE DISTANCE ......... ligne  36
// 3. HACHAGE ........................ ligne  56
// 4. LIBERATION DE LA MEMOIRE ....... ligne  63
//
// #############################################
#ifndef __DISTANCE__H__
#define __DISTANCE__H__

#include "sequence.h"
#include "list.h"

// #####################################
// 1. TYPES
// #####################################

    //Définition du type Distance_Nucleotide
    typedef struct Distance_Nucleotide
    {
        double tab[NOMBER_NUCLEOTIDES][NOMBER_NUCLEOTIDES];  
    }D_Nucleotide;

    //Définition du type Distance
    typedef struct Distance
    {
        List *list;
    }Distance;

// #####################################
// 2. GESTION D'UNE DISTANCE
// #####################################


    //Créer et initialiser le type Distance_Nucleotide
    D_Nucleotide creat_and_init();

    //Assigner le type Distance_Nucleotide
    D_Nucleotide set_distance(D_Nucleotide);

    //Retourne la distance de deux nucléotides.
    double get_distance_nucleotide(char, char, D_Nucleotide);

    //Retourne la distance d'édition de deux Séquences. alias D1
    double first_distance(Sequence, Sequence, D_Nucleotide);

    //Retourne la distance d'édition de tous les paires séquences stockées dans le type Distance.
    Distance distance(Sequence s[],  D_Nucleotide);

// #####################################
// 3. HACHAGE
// #####################################  

    //Retourner la clé du caractère haché.
    int hacher(char s);

// #####################################
// 4. LIBERATION DE LA MEMOIRE
// #####################################
    
    //Libération de la mémoire allouée.
    void free_tab_list(Distance d);


#endif