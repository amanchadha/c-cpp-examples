#include <stdio.h>

void myprintf(char *s)
{
    printf("Overridden...\n");
}

void outside()
{
    printf("Outside...\n");
}
