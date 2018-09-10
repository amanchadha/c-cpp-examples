// C/C++ program to remove all adjacent duplicates from a string
#include <iostream>
#include <string.h>
using namespace std;

//e.g. apple  -->  ale
//     bottom -->  bm
 
// Recursively removes adjacent duplicates from str and returns
// new string. las_removed is a pointer to last_removed character
char* removeUtil(char *str, char *last_removed)
{
    // If length of string is 1 or 0
    if (str[0] == '\0' || str[1] == '\0')
        return str;
 
    // Remove leftmost same characters and recur for remaining string
    if (str[0] == str[1])
    {
        *last_removed = str[0];
        while (str[1] && str[0] == str[1])
            str++;

        str++; //start from the first non-repeating/non-duplicate/unique character
        return removeUtil(str, last_removed);
    }
 
    // At this point, the first character is definiotely different 
    // from its adjacent. Ignore first character and recursively 
    // remove characters from remaining string
    char* rem_str = removeUtil(str+1, last_removed);
 
    // Check if the first character of the rem_string matches with 
    // the first character of the original string
    // This is needed for a string like "abba" to should have an output of a blank string.
    if (rem_str[0] && rem_str[0] == str[0])
    {
        cout << "Special case 2: " << "rem_str: " << rem_str << "\tstr: " << str << endl;
        *last_removed = str[0];
        return (rem_str+1); // Remove first character
    }
 
    // If remaining string becomes empty and last removed character
    // is same as first character of original string. 
    // This is needed for a string like "acbbcddc" to have an output of 'a' rather than 'ac'.
    if (rem_str[0] == '\0' && *last_removed == str[0])
    {
         cout << "Special case 2: " << "rem_str: " << rem_str << "\tstr: " << str << "\tlast_removed: " << *last_removed << endl;
         return rem_str;
    }

    //cout << "***Special case***: " << "rem_str: " << rem_str << endl; //"\tstr: " << str << "\tlast_removed: " << *last_removed << endl;
 
    // If the two first characters of str and rem_str don't match, 
    // append first character of str before the first character of
    // rem_str. 
    // This is needed for a string like "abbc" to have an output of 'ac'.
    rem_str--;
    rem_str[0] = str[0];
    cout << "Special case 3: " << "rem_str: " << rem_str << "\tstr: " << str << "\tlast_removed: " << *last_removed << endl;
    return rem_str;
}
 
char *remove(char *str)
{
    char last_removed = '\0';
    return removeUtil(str, &last_removed);
}
 
// Driver program to test above functions
int main()
{
    cout << "*******\nString 1\n*******\n" << endl;
    char str1[] = "geeksforgeeg";
    cout << remove(str1) << endl;
 
    cout << "*******\nString 2\n*******\n" << endl;
    char str2[] = "azxxxzy";
    cout << remove(str2) << endl;
 
    cout << "*******\nString 3\n*******\n" << endl;
    char str3[] = "caaabbbaac";
    cout << remove(str3) << endl;
 
    cout << "*******\n>>> String 4\n*******\n" << endl;
    char str4[] = "gghhg";
    cout << remove(str4) << endl;
 
    cout << "*******\nString 5\n*******\n" << endl;
    char str5[] = "aaaacddddcappp";
    cout << remove(str5) << endl;
 
    cout << "*******\nString 6\n*******\n" << endl;
    char str6[] = "aaaaaaaaaa";
    cout << remove(str6) << endl;
 
    cout << "*******\nString 7\n*******\n" << endl;
    char str7[] = "qpaaaaadaaaaadprq";
    cout << remove(str7) << endl;
 
    cout << "*******\nString 8\n*******\n" << endl;
    char str8[] = "acaaabbbacdddd";
    cout << remove(str8) << endl;
 
    cout << "*******\n>>> String 9\n*******\n" << endl;
    char str9[] = "acbbcddc";
    cout << remove(str9) << endl;
    
    cout << "*******\nString Case 3\n*******\n" << endl;
    char str10[] = "abbc";
    cout << remove(str10) << endl;
    
    cout << "*******\nString Case 1\n*******\n" << endl;
    char str11[] = "abba";
    cout << remove(str11) << endl;

    cout << "*******\nString Example 1\n*******\n" << endl;
    char str12[] = "apple";
    cout << remove(str12) << endl;
    
    cout << "*******\nString Example 2\n*******\n" << endl;
    char str13[] = "bottom";
    cout << remove(str13) << endl;    
 
    return 0;
}
