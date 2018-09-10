#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    char *str1 = "Hi!";
    char str2[] = "Hello!";
    string str3("Hi!");
    string str4 = "Hello!";

    int i;

    printf("%s\t%s\t%s\t%s\n", str1, str2, str3.c_str(), str4.c_str()); //no need to worry about iterating until the delimiter 
    cout << str1 << "\t" << str2 << "\t" << str3 << "\t" << str4 << endl; //no need to worry about iterating until the delimiter 

    for (i = 0; str1[i]; ++i)
      cout << str1[i];
    cout << endl;
}
