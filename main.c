#include <stdio.h>
#include "types.h"
#include "common.h"

int main(int argc, char *argv[])
{
    //Status s1;
    //OperationType o1;
    if(check_option(argv[1]) == e_help)
    {
        help_menu();
    }
    else if(check_option(argv[1]) == e_view)
    {
        view_tag();
    }
    else if(check_option(argv[1]) == e_unsupported)
    {
        printf("please give proper option\n");
    }

}