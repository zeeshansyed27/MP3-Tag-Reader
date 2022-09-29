#include <stdio.h>
#include "types.h"
#include "common.h"

int main(int argc, char *argv[])
{
    if(argc > 2)
    {
	if(check_option(argv[1]) == e_help)
	{
	    help_menu();
	}
	else if(check_option(argv[1]) == e_view)
	{
	    view_info(argv[2]);
	}
	else if(check_option(argv[1]) == e_edit)
	{
	    edit_info(argv, argc);
	}
	else if(check_option(argv[1]) == e_unsupported)
	{
	    printf("Please give proper option\n");
	    help_menu();
	}
    }
    else
    {
	printf("Please give proper option\n");
	help_menu();
    }
}
