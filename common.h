#ifndef COMMON_H
#define COMMON_H

#include "types.h"
#include <stdio.h>
typedef struct MP3
{
    FILE *original;
    FILE *temp;
    char string[5];
}mp3tag;

OperationType check_option(char argv[]);
Status help_menu(void);
Status view_info(char * filename);
Status print_tag(mp3tag *read);
int get_size(mp3tag *read);
Status edit_info(char * arguments[], int argc);
Status edit_tag(mp3tag *read, char *str, int str_len, int count);
#endif
