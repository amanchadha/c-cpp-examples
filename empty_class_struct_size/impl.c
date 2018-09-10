#include <stdio.h>

struct BlankStruct
{
};

struct FilledStruct
{
  int x;
};

int main(void)
{
  struct BlankStruct s;
  struct FilledStruct fs;

  printf("Sizeof blank struct...\n");
  printf("%d\n", sizeof(s));
  
  printf("Sizeof filled struct...\n");
  printf("%d\n", sizeof(fs));
}
