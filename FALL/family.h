// ############################################
//                  SOMMAIRE
// ############################################
//
// 1. TYPES .......................... ligne  20
// 2. GESTION D'UNE FAMILLE .......... ligne  42
// 3. AFFICHAGE ...................... ligne  73
// 4. LIBERATION DE LA MEMOIRE ....... ligne  84
//
// #############################################

#ifndef __FAMILY__H__
#define __FAMILY__H__

#include "alignement.h"
#include "distance.h"

// #####################################
// 1. TYPES
// #####################################

    //Définition du type Family
    typedef struct Family
    {
        int number_element;
        double d_min;
        Sequence *s;
        Sequence consensus;

    }Family;

    //Définition du type Tab_Family
    typedef struct Tab_Family
    {
        int number_family;
        Family *f;

    }Tab_Family;

// #####################################
// 2. GESTION D'UNE FAMILLE
// #####################################

    //Retourne la famille crée.
    Family creat_family();

    //Ajouter un membre dans la famille et retourner la famille
    Family add_member(Family f, Sequence s);

    //Retourner le un tableau de familles.
    Tab_Family reseach_family(Tab_Family tab_f, Distance tab_distance_edition, Sequence s[]);

    //Retourne true si une famille est vide, sinon false.
    Bool is_empty_family(Family f);

    //Retourne true si le tableau de famille est vide, sinon false.
    Bool is_empty_tab_family(Tab_Family tab_f);

    //Retourne la distance minimale.
    double set_distance_min(double d);

    //Initialise le type Tab_Family et le retourner
    Tab_Family init_tab_Family();

    //Ajouter une famille dans le tableau et retourne le type Tab_Family
    Tab_Family add_family(Tab_Family tab_f, Family f);

    //Recherche la séquence consensus et retourne le type Tab_Family.
    Tab_Family findSequenceConsensus(Tab_Family tab_f);

// #####################################
// 3. AFFICHAGE
// #####################################

    //Afficher les membres d'une famille.
    void print_family(Family f);

    //Afficher les membres d'une familles.
    void print_tab_family(Tab_Family tab_f);

// #####################################
// 4. LIBERATION DE LA MEMOIRE
// #####################################

    //Libérer la mémoire allouer le type Tab_Family
    void free_tab_family(Tab_Family tab_f);

    //Libérer la mémoire allouer le type Family
    void free_family(Family f);

#endif