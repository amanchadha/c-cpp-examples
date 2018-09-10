#include <iostream>

using namespace std;

int main()
{
  char* str = "hey";

  for (int i = 0; str[i] != '\0'; ++i)
    cout << str[i];

  cout << endl;

  //for (int i = 0; str[i] != NULL; ++i)
  //  cout << str[i];

  char* str1 = NULL;
  if (!str1)
    cout << "NULL String" << endl;

  char* str2 ='\0';
  if (!str2)
    cout << "NULL Terminated String" << endl;
}
