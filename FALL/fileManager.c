// ############################################
//                  SOMMAIRE
// ############################################
//
// 1. GESTION D'UN FICHER ............ ligne   15
// 2. GESTION D'UN DOSSIER ........... ligne  143
// 3. GESTION D'ERREURS .............. ligne  161
// 4. LIBERATION DE LA MEMOIRE ....... ligne  175
//
// #############################################

#include "fileManager.h"

// #####################################
// 1. GESTION D'UN FICHIER
// #####################################

//Retourne true si l'argument est null sinon false.
Bool is_null(void *arg)
{
    return ((arg == NULL) ? true : false);
}

//Ouvrir un fichier, si le fichier est ouvert retoun le fichier sinon message Erreur.
FILE *open_file(char *name_file, char *mode)
{
    FILE *file = fopen(name_file, mode);

    if(is_null(file))
    {
        fprintf(stderr, "Cant open file %s\n", name_file);
        exit(EXIT_FAILURE);
    }

    return file;
}

//Retourne la ligne lue.
char *read_row(FILE *file, char *string, int size)
{
    if(is_null(string))
        return NULL;
        
    //fgets(string, size, file);

    return fgets(string, size, file);
}

//Retourne le caractère lu s'il est différent de EOF.
char read_char(FILE* file)
{
    int c = getc(file);
    if(c == EOF)
        return -1;
    return c;
}

//Ferme le fichier ouvert.
void close_file(FILE *file)
{
    if(fclose(file) == EOF)
    {
        fprintf(stderr, "Cant close file.\n");
        exit(EXIT_FAILURE);
    }
}
//Erire l'argument dans le fichier ouvert.
void write_file(FILE *file, char *string)
{
    int status = fputs(string, file);
    if(status == EOF)
    {
        fprintf(stderr, "Cant write in the file.\n");
        return;
    }
}

//Retourne le nombre de ligne du fichier.
int nomber_row(FILE *file)
{
    int nomber_rows = 0, c = 0;

    while((c = read_char(file)) != EOF)
        if(c == '\n')
            ++nomber_rows;
    return nomber_rows;
}

//Initialise le nom du fichier.
File init_file(char *names)
{
    File f;
    f.length = strlen(names) + 1;
    f.name = (char*) malloc(sizeof(char)*f.length);
    if(is_null(f.name))
    {
        fprintf(stderr, "Cant init file:(\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < f.length; i++)
        f.name[i] = names[i];

    return f;
}

//Initialise le tableau contenant le nom des fichiers.
Tab_File init_tab_file()
{
    Tab_File t;

    t.file = NULL;
    t.number_file = 0;

    return t;
}

//Assigne le tableau de fichier.
Tab_File assigne_tab_file(char *name_directory)
{
    DIR *dire = open_directory(name_directory);
    Tab_File tab = init_tab_file();

    struct dirent *d;
    d = readdir(dire);
    while (!is_null(d))
    {
        if(strcmp(d->d_name, FULL_STOP) != 0  &&  strcmp(d->d_name, TWO_FULL_STOP) != 0)
        {
            File f = init_file(d->d_name);
            tab.file = (File *)realloc(tab.file, sizeof(File)*(tab.number_file + 1));
            error(tab.file, "Cant assign tab file");
            tab.file[tab.number_file] = f;
            tab.number_file++; 
        }
        d = readdir(dire);
    } 
    free(d);
    free(dire);
    return tab;    
}

// #####################################
// 2. GESTION D'UN DOSSIER
// #####################################

//Ouvre un repertoire et le retourne
DIR *open_directory(char *directory_name)
{
    DIR *d = opendir(directory_name);

    if(is_null(d))
    {
        fprintf(stderr, "Cant open directory.\n");
        exit(EXIT_FAILURE);
    }

    return d;
}

// #####################################
// 3. GESTION D'ERREUR 
// #####################################

//Affiche un message d'erreur s'il y'a des erreurs.
void error(void *e, char *message)
{
    if(is_null(e))
    {
        fprintf(stderr, "%s:(\n", message);
        exit(EXIT_FAILURE);
    }
}

// #####################################
// 5. LIBERATION DE LA MEMOIRE
// #####################################

//Libére la mémoire allouer pour stocker le nom d'un fichier.
void free_file_sequence(File f)
{
    error(f.name, "Cant free file sequence");
    free(f.name);
}

//libere le table de fichier allouer.
void free_tab_file(Tab_File tab_f)
{
    error(tab_f.file, "Cant free tab file");
    for(int i = 0; i < tab_f.number_file; i++)
        free_file_sequence(tab_f.file[i]);
    
    free(tab_f.file);
}