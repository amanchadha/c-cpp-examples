#include <stdio.h>

int main()
{
    const int a = 5;

    static int b;
  
    printf("%d %d", a, b);
    
    b = 10;

    b = 20;
    
    printf("\n\n%d %d", a, b);

    for (int i = 0 ; i < 5; i++)
    {
      static int x = 100;
      int y = 100;
      printf("\n\n%d %d", x++, y++);
    }  

    int z = 2;
    printf("\n\n%d", z);
}
