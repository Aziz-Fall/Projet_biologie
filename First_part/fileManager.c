#include "fileManager.h"

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
    string = fgets(string, size, file);

    if(is_null(string))
        return NULL;

    return string;
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