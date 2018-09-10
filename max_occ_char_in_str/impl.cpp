// C++ program to output the maximum occurring character in a string
#include<iostream>
#define ASCII_SIZE 256
using namespace std;
 
char getMaxOccuringChar(char* str)
{
    // Create array to keep the count of individual characters
    int count[ASCII_SIZE];
 
    // Initialize the count array to zero
    for (int j=0; j < ASCII_SIZE; j++)
        count[j] = 0;
 
    // Utility variables
    int len = strlen(str);
    int max = -1;
    char c;
 
    // Traversing through the string and maintaining the count of
    // each character
    for (int i = 0; i < len; i++) {
        if (max < count[str[i]]) {
            max = count[str[i]];
            c = str[i];
        }
    }
 
    return c;
}
 
// Driver program to test the above function
int main()
{
    //char* str = "sample string";
    char *str = "abbbbbbbbbbbbbbcccc";
    cout << "Max occurring character is "
         << getMaxOccuringChar(str);
}
