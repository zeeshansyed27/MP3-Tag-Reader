#include "types.h"
#include "common.h"
#include <stdio.h>
#include <string.h>


OperationType check_option(char argv[])
{
    if (!strcmp(argv, "--help"))
    {
        return e_help;
    }
    else if (!strcmp(argv, "-e"))
    {
        return e_edit;
    }
    else if (!strcmp(argv, "-v"))
    {
        return e_view;
    }
    else
    {
        return e_unsupported;
    }
}

Status help_menu(void)
{
    printf("usage:  mp3tag -[tTaAycg] \"value\" FileName\n");
    printf("        mp3tag -v\n");
    printf("-t Modifies a Title tag\n");
    printf("-T Modifies a Track tag\n");
    printf("-a Modifies a Artist tag\n");
    printf("-A Modifies a Album tag\n");
    printf("-y Modifies a Year tag\n");
    printf("-c Modifies a Comment tag\n");
    printf("-g Modifies a Genre tag\n");
    printf("--help Displays this help info\n");
    printf("-v Prints version info\n");
    return e_success;
}

Status view_tag(void)
{
    mp3tag read;
    read.original = fopen("sample.mp3", "r");
    fseek(read.original, 10, SEEK_SET);
    fread(read.string, 1, 4, read.original);
    read.string[4] = '\0';
    if(!(strcmp(read.string, "TIT2")))
    {
        printf("Title       :   ");
        print_tag(&read);
    }
    else
    {
        printf("Unable to read Title(TIT2)\n");
        return e_failure;
    }

    fread(read.string, 1, 4, read.original);
    //read.string[4] = '\0';
    if(!strcmp(read.string, "TPE1"))
    {
        printf("Artist       :   ");
        print_tag(&read);
    }
    else
    {
        printf("Unable to read Artist(TPE1)\n");
        return e_failure;
    }

    fread(read.string, 1, 4, read.original);
    //read.string[4] = '\0';
    if(!strcmp(read.string, "TALB"))
    {
        printf("Album       :   ");
        print_tag(&read);
    }
    else
    {
        printf("Unable to read Album(TALB)\n");
        return e_failure;
    }

    fread(read.string, 1, 4, read.original);
    //read.string[4] = '\0';
    if(!strcmp(read.string, "TYER"))
    {
        printf("Year       :   ");
        print_tag(&read);
    }
    else
    {
        printf("Unable to read Year(TYER)\n");
        return e_failure;
    }

    fread(read.string, 1, 4, read.original);
    //read.string[4] = '\0';
    if(!strcmp(read.string, "TCON"))
    {
        printf("Genre       :   ");
        print_tag(&read);
    }
    else
    {
        printf("Unable to read Genre(TCON)\n");
        return e_failure;
    }

    fread(read.string, 1, 4, read.original);
    //read.string[4] = '\0';
    if(!strcmp(read.string, "COMM"))
    {
        printf("Comment       :   ");
        print_tag(&read);
    }
    else
    {
        printf("Unable to read Comment(COMM)\n");
        return e_failure;
    }

    return e_success;
}

Status print_tag(mp3tag *read)
{
    char size[4];
    char content[100];
    fread(size, 4, 1, read->original);
    fseek(read->original, 3, SEEK_CUR);
    fread(content, 1, size[3]-1, read->original);
    //printf("%#x\n ", size[3]);
    printf("%s\n", content);
    return e_success;
}
