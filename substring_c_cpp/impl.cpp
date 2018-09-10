#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
   char str1[20] = "ThisIsString1";
   char str2[20] = "Is";
   char substr[20];

   cout << "C Style String Sub-String" << endl;
   
   //find substring in C
   printf("Checking if str2 is a substring of str1: ");
   (strstr(str1, str2) != NULL) ? printf("Yes\n") : printf("No\n");

   //get substring in C
   strncpy((char*) substr, (char*) str2, 3);
   printf("The strings are: %s\t%s\n", substr, str2);

   //for(int i = 0; i < 2; i++)
   //   str1[i] = str2[i];

   string str3 = "ThisIsString1"; 
   string str4 = "Is"; 
   
   cout << "C++ Style String Sub-String" << endl;
   
   //find substring in C++
   cout << "Checking if str4 is a substring of str3: ";
   (str3.find(str4) != string::npos) ? cout << "Yes" << endl : cout << "No" << endl; 
 
   //get substring in C++
   cout << "The strings are: " << str3.substr(4, 2) << "\t" << str4 << endl; 
   
   return(0);
}
