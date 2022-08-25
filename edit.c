/*
Name: Syed Zeeshan Ulla
Date: 00/00/2022
Description:
Input:
Output:
*/

#include <stdio.h>
int main(int argc, char *argv[])
{
    char value[1] = {0x20};
    FILE *ptr = fopen(argv[1], "w+");
    fseek(ptr, 199, SEEK_SET);
    fwrite(value, 1, 1, ptr);
    //printf("%#x\n", value[0]);
    return 0;
}
