#include <iostream>

using namespace std;

int main()
{
  int arr1[] = {1, 2, 3};
  int arr2[3] = {1, 2, 3};
  int* arr3 = (int*) &arr1;

  cout << "Size of arr1: " << sizeof(arr1) << endl;
  cout << "Size of arr2: " << sizeof(arr2) << endl;
  cout << "Size of arr3: " << sizeof(arr3) << endl;
  
  cout << "Number of elements in arr1: " << sizeof(arr1)/sizeof(arr1[0]) << endl;
  cout << "Number of elements in arr2: " << sizeof(arr2)/sizeof(arr2[0]) << endl;
  cout << "Number of elements in arr3: " << sizeof(arr3)/sizeof(arr3[0]) << endl;
}     
