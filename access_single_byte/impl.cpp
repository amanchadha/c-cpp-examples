#include <stdio.h>

int main()
{
  int x = 256;
  char *p = (char*) &x;
  printf("%d\n",*p++);
  printf("%d\n",*p++);
  printf("%d\n",*p++);
  printf("%d\n",*p);
  printf("Size of ptr: %d\n", sizeof(p));
}
