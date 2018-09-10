#include <iostream>

using namespace std;

int main()
{
    int n = 10, count = 0;

    for (int i = 0; i < n-2; i++)
       for (int j = i+1; j < n-1; j++)
           for (int k = j+1; k < n; k++)
           {
               count++;
               printf("i, j, k values are %d, %d, %d\n", i, j, k);
           }

    printf("--> Loop count is %d\n", count);
    count = 0;
    printf("\n*******\n\n");
    
    for (int i = 0; i < n; i++)
       for (int j = i+1; j < n; j++)
           for (int k = j+1; k < n; k++)
           {
               count++;
               printf("i, j, k values are %d, %d, %d\n", i, j, k);
           }
    
    printf("--> Loop count is %d\n", count);
    count = 0;
    printf("\n*******\n\n");
    
    for (int i = 0; i < n-1; i++)
       for (int j = i+1; j < n; j++)
       {
           count++;
           printf("i, j values are %d, %d\n", i, j);
       }

    printf("--> Loop count is %d\n", count);
    count = 0;
    printf("\n*******\n\n");
    
    for (int i = 0; i < n; i++)
       for (int j = i+1; j < n; j++)
       {
           count++;
           printf("i, j values are %d, %d\n", i, j);
       }
    
    printf("--> Loop count is %d\n", count);    
}
