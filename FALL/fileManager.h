// ############################################
//                  SOMMAIRE
// ############################################
//
// 1. TYPES .......................... ligne  24
// 2. GESTION D'UN FICHER ............ ligne  50
// 3. GESTION D'UN DOSSIER ........... ligne  84
// 4. GESTION D'ERREURS .............. ligne  94
// 5. LIBERATION DE LA MEMOIRE ....... ligne  98
//
// #############################################

#ifndef __FILEMANAGER__H__
#define __FILEMANAGER__H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include "const.h"

// #####################################
// 1. TYPES
// #####################################

    //Définition du type Bool: booleen
    typedef enum 
    {
        false,
        true
    }Bool;

    //Définition du type File: fichier
    typedef struct File
    {
        int length;
        char *name;  
    }File;

    //Définition du typde Tab_File: tableau de fichier.
    typedef struct Tab_File
    {
        int number_file;
        File *file;

    }Tab_File;

// #####################################
// 2. GESTION D'UN FICHIER
// #####################################

    //Créer, ouvrir un ficher et le retourne
    FILE *open_file(char*, char*);

    //Retourne le contenu d'une ligne de fichier.
    char *read_row(FILE*,char *string, int);

    //Ecrire dans un fichier.
    void write_file(FILE*, char*);

    //Lire un caractère dans le fichier et le retourne.
    char read_char(FILE*);

    //Retourne le nombre de ligne d'un fichier.
    int nomber_row(FILE*);

    //Fermer un fichier.
    void close_file(FILE*);

    //Initialiser un type File et le retourne
    File init_file(char *name);

    //Retourner un tableau de fichier, lu à partir d'un dossier.
    Tab_File assigne_tab_file(char *name_directory);
    
    //Créer et initialiser un tableau de fichier.
    Tab_File init_tab_file();

    //Retrourne true si le argument est NULL sinon false.
    Bool is_null(void*);

// #####################################
// 3. GESTION D'UN DOSSIER
// #####################################

    //Ouvrir un dossier et retourne le nom du dossier ouvert.
    DIR *open_directory(char *directory_name);

// #####################################
// 4. GESTION D'ERREUR 
// #####################################

    //Affiche un message d'erreur s'il y'a erreur.
    void error(void *e, char *message);

// #####################################
// 5. LIBERATION DE LA MEMOIRE
// #####################################

    void free_tab_file(Tab_File tab_f);
    
#endif
