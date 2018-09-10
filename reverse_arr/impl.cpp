#include <stdio.h>

/* Function to print reverse of the passed array */
void reverseArr(int *arr, int count)
{
   if (count--)
   {
       reverseArr(arr+1, count);
   }
      
   printf("%d", *arr);
}

/* Function to print reverse of the passed string */
void reverseStr(char *str)
{
   if (*str)
   {
       reverseStr(str+1);
       printf("%c", *str);
   }
}
 
/* Driver program to test above function */
int main()
{
   int arr[] = {1, 2, 3};
   int n = sizeof(arr)/sizeof(arr[0]);
   reverseArr(arr, n-1);
   printf("\n");

   char a[] = "Geeks for Geeks";
   reverseStr(a);
   printf("\n");

   return 0;
}
