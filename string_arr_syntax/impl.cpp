#include <iostream>

using namespace std;

int main()
{
  int arr1[] = {1,2,3};
  int* arr2 = (int*) &arr1;

  //char* str1 = {'a','b','c','\0'};
  char* str2 = "abc";
  char str3[] = {'a','b','c','\0'};
  char str4[] = "abc";

  cout << arr1[0] << " " << arr2[0] << endl;
  cout << str2 << " " << str3 << " " << str4 << endl;
}
