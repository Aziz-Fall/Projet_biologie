// ############################################
//                   SOMMAIRE
// ############################################
//
// 1. TYPES .......................... ligne  18
// 2. GESTION D'UNE LISTE ............ ligne  30
// 3. AFFICHAGE D'UNE LISTE .......... ligne  49
// 4. LIBERATION DE LA MEMOIRE ....... ligne  56
//
// #############################################

#ifndef __LIST__H__
#define __LIST__H__

#include "fileManager.h"

// #####################################
// 1. TYPES
// #####################################

    //Définition du type List
    typedef struct Element
    {
        int index;
        double d_edition;
        struct Element *next;
    }Element, *List;

// #####################################
// 2. GESTION D'UNE LISTE 
// #####################################

    //Créer et retourne le type List
    List creat_list();

    //Insérer un élement dans la liste et retourne le type List
    List insert(List l, int index, double d_edition);

    //Supprimer un élement dans la liste et retourne le typde List
    List delete_element(List l);

    //Retourne le nombre d'occurence de la distance minimale.
    int count_distance_min(List l);

    //Retourne la distance d'édition minimale 
    double d_edition_min(List l);

// #####################################
// 3. AFFICHAGE D'UNE LISTE
// #####################################

    //Afficher le contenu du type List
    void print_list(List l);

// #####################################
// 4. LIBERATION DE LA MEMOIRE
// #####################################

    //Libérer la mémoire allouer.
    void free_list(List l);

#endif