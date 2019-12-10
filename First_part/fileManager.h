#ifndef __FILEMANAGER__H__
#define __FILEMANAGER__H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

#define  MODE_READ  "r"
#define  MODE_WRITE "w"
#define  FULL_STOP "."
#define TWO_FULL_STOP ".."
#define  MAX_SIZE 50
typedef enum 
{
    false,
    true
}Bool;

typedef struct File
{
    int length;
    char *name;  
}File;

typedef struct Tab_File
{
    int number_file;
    File *file;

}Tab_File;

FILE *open_file(char*, char*);
char *read_row(FILE*,char *string, int);
void write_file(FILE*, char*);
char read_char(FILE*);
int nomber_row(FILE*);
void close_file(FILE*);
Bool is_null(void*);
DIR *open_directory(char *directory_name);
Tab_File assigne_tab_file(char *name_directory);
File init_file(char *name);
Tab_File init_tab_file();
void free_tab_file(Tab_File tab_f);
void error(void *e, char *message);

#endif
