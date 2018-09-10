#include <stdio.h>
#include "intercept.h"

void myprintf(char *s);
void outside();

int main()
{
    printf("Hey");
    outside();
}
