#include "types.h"
#include "common.h"
#include <stdio.h>
#include <string.h>

Status edit_info(char * arguments[], int argc)
{
    if(argc < 5)
    {
	printf("Please pass 5 arguments to edit mp3 file information\n");
	help_menu();
	return e_failure;
    }

    if(strcmp(&(arguments[2][6]), ".mp3") != 0)
    {
	printf("Please pass .mp3 file as input file\n");
	return e_failure;
    }

    mp3tag read;
    read.original = fopen("sample.mp3", "r+");
    fseek(read.original, 10, SEEK_SET);
    int size, str_len = strlen(arguments[4]);
    int count = 0;
    char null = '\0';
    switch(arguments[3][1])
    {
	case 't':
	    count = 0;
	    edit_tag(&read, arguments[4], str_len, count);
	    break;
	case 'a':
	    count = 1;
	    edit_tag(&read, arguments[4], str_len, count);
	    break;
	case 'A':
	    count = 2;
	    edit_tag(&read, arguments[4], str_len, count);
	    break;
	case 'y':
	    count = 3;
	    edit_tag(&read, arguments[4], str_len, count);
	    break;
	case 'g':
	    count = 4;
	    edit_tag(&read, arguments[4], str_len, count);
	    break;
	case 'c':
	    count = 5;
	    edit_tag(&read, arguments[4], str_len, count);
	    break;
	default:
	    printf("Please pass proper edit tag option -[taAycg]\n");
	    return e_failure;
    }

    fclose(read.original);
    return e_success;
}



Status edit_tag(mp3tag *read, char *str, int str_len, int count)
{
    char null = '\0';
    int size;
    //Moving till the tag which is before before the tag thas has to be edited 
    for(int i = 1; i <= count; i++)
    {
	fseek(read->original, 4, SEEK_CUR);
	size = get_size(read);
	fseek(read->original, 3, SEEK_CUR);
	fseek(read->original, size, SEEK_CUR);
    }
    //editing the requested tag
    fseek(read->original, 4, SEEK_CUR);
    size = get_size(read);
    
    //reading size of tag and checking whether we have required size
    if(str_len > size)
    {
    	printf("Unable to edit. Size of given string is more than tag size.\n");
    	return e_failure;
    }
    
    fseek(read->original, 3, SEEK_CUR);
    fwrite(str, 1, str_len, read->original);
    //size = size - str_len;
    //char clear[size] = {};
    fwrite(&null, 1, size - str_len, read->original);
    printf("Your information has been edited!!\n");
    return e_success; 
}
