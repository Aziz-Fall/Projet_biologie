// ############################################
//                  SOMMAIRE
// ############################################
//
// 1. TYPES .......................... ligne 18
// 2. GESTION D'UNE SEQUENCE ......... ligne 30
// 3. AFFICHAGE ...................... ligne 46
// 4. LIBERATION DE LA MÉMOIRE ....... ligne 53
//
// #############################################

#ifndef __SEQUENCE__H__
#define __SEQUENCE__H__

#include "fileManager.h"

// #####################################
// 1. TYPES
// #####################################

    //Définition du type Sequence
    typedef struct Sequence
    {
        int length;
        char *tab_nucleotide;

    }Sequence;

// #####################################
// 2. GESTION D'UNE SEQUENCE
// #####################################

    //Créer et initialiser une séquence et la retourne.
    Sequence creat_init_sequence(char*);

    //Assigner un tableau de séquence.
    void assign_tab_sequences(Sequence s[], int nb_element, Tab_File tab_file);

    //Comparer deux séquences et retourne la valeurs de la comparaison.
    int compare_sequence(Sequence first, Sequence second);

// #####################################
// 3. AFFICHAGE
// #####################################

    //Afficher une séquence.
    void print_sequence(Sequence s, int nb_nucleotides);

// #####################################
// 4. LIBERATION DE LA MEMOIRE
// #####################################

    //Libération de la mémoire allouer pour chaque séquence du tableau passé en argument.
    void free_tab_sequence(Sequence s[], int nb_sequence);

#endif