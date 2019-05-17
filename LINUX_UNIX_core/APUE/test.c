#include "header.h"

int main(int argc, char *argv[])
{
    printf("test.c\n");
    for(int i=1;i<argc;i++)
        printf("%s\n", argv[i]);
    exit(0);
}