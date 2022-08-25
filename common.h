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
Status view_tag(void);
Status print_tag(mp3tag *read);
#endif
