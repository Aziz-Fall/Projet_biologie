#ifndef __FILEMANAGER__H__
#define __FILEMANAGER__H__

#include <stdlib.h>
#include <stdio.h>

#define  MODE_READ  "r"
#define  MODE_WRITE "w"
#define  MAX_SIZE 50
typedef enum 
{
    false,
    true
}Bool;

FILE *open_file(char*, char*);
char *read_row(FILE*,char *string, int);
void write_file(FILE*, char*);
char read_char(FILE*);
int nomber_row(FILE*);
void close_file(FILE*);
Bool is_null(void*);

#endif
