#include <iostream>

using namespace std;

int main()
{
  int arr[] = {1,2,3};
  cout << sizeof(arr) << endl;

  int *arr1 = new int[4];//{1,2,3};
  cout << sizeof(arr1) << endl;

  int *arr2 = &arr[0];
  cout << sizeof(arr2) << endl;

  int *arr3 = arr;
  cout << sizeof(arr3) << endl;
}
