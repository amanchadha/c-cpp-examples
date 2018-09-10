#include <stdlib.h>
#include <iostream>

using namespace std;

//modify (set) strings

int main()
{
  //The below program may crash (gives segmentation fault error) because the line *(str+1) = ‘n’ tries to write a read only memory.
 {
    char *str; 
    str = "GfG";     /* Stored in read only part of data segment */
    //*(str+1) = 'n'; /* Problem:  trying to modify read only memory */
 }

  //Below program works perfectly fine as str[] is stored in writable stack segment.
 {
    char str[] = "GfG";  /* Stored in stack segment like other auto variables */
    *(str+1) = 'n';   /* No problem: String is now GnG */
    cout << str << endl;
 }


  //Below program also works perfectly fine as data at str is stored in writable heap segment.
  {
    int size = 4;
 
    /* Stored in heap segment like other dynamically allocated things */
    char *str = (char *)malloc(sizeof(char)*size);
    *(str+0) = 'G'; 
    *(str+1) = 'f';  
    *(str+2) = 'G';    
    *(str+3) = '\0';  
    *(str+1) = 'n';  /* No problem: String is now GnG */
    cout << str << endl;
  }
}     
