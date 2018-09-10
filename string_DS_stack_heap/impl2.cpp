#include <stdlib.h>
#include <iostream>

using namespace std;

//return (get) string

char *getString_DS()
{
  char *str = "GfG"; /* Stored in read only part of shared segment */
 
  /* No problem: remains at address str after getString() returns*/
  return str;  
}     

char *getString_heap()
{
  int size = 4;
  char *str = (char *)malloc(sizeof(char)*size); /*Stored in heap segment*/
  *(str+0) = 'G'; 
  *(str+1) = 'f';  
  *(str+2) = 'G';
  *(str+3) = '\0';  
   
  /* No problem: string remains at str after getString() returns */   
  return str;  
}     

char *getString_stack()
{
  char str[] = "GfG"; /* Stored in stack segment */
 
  /* Problem: string may not be present after getSting() returns */
  return str; 
}     
 
int main()
{
  //The below program works perfectly fine as the string is stored in a shared segment 
  //and data stored remains there even after return of getString()
  printf("DS: %s\n", getString_DS());  

  //The below program alse works perfectly fine as the string is stored in heap segment 
  //and data stored in heap segment persists even after return of getString()
  printf("Heap: %s\n", getString_heap());  

  //But, the below program may print some garbage data as string is stored in stack frame of function getString() 
  //and data may not be there after getString() returns.
  printf("Stack: %s\n", getString_stack());  
  return 0;
}
