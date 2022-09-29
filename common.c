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
    printf("usage:  mp3tag -e Filename.mp3 -[taAycg] \"value\"\n");
    printf("        mp3tag -v Filename.mp3\n");
    printf("        mp3tag --help\n");
    printf("-t Modifies a Title tag\n");
    printf("-a Modifies a Artist tag\n");
    printf("-A Modifies a Album tag\n");
    printf("-y Modifies a Year tag\n");
    printf("-c Modifies a Comment tag\n");
    printf("-g Modifies a Genre tag\n");
    printf("--help Displays this help info\n");
    printf("-v Prints version info\n");
    printf("-e option to edit\n");
    return e_success;
}

Status view_info(char * filename)
{
    if(strcmp(&(filename[6]), ".mp3") != 0)
    {
	printf("Please pass .mp3 file as input file\n");
	return e_failure;
    }

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
	printf("Artist      :   ");
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
	printf("Year        :   ");
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
	printf("Comment     :   ");
	print_tag(&read);
    }
    else
    {
	printf("Unable to read Comment(COMM)\n");
	return e_failure;
    }

    fclose(read.original);
    return e_success;
}

Status print_tag(mp3tag *read)
{
    int size;
    char content[100] = {};
    size = get_size(read);
    fseek(read->original, 3, SEEK_CUR);
    fread(content, 1, size, read->original);
    printf("%s\n", content);
    return e_success;
}

int get_size(mp3tag *read)
{
    char read_size[4];
    int size;
    fread(read_size, 4, 1, read->original);
    size = ((int)read_size[0] << 24) | ((int)read_size[1] << 16) | ((int)read_size[2] << 8) | ((int)read_size[3]);
    size = size - 1;
    return size;
}
