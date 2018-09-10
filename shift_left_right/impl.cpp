#include <iostream>

using namespace std;

void printArr(int arr[], int n)
{
  for (int i = 0 ; i < n ; ++i)
    cout << arr[i];

  cout << endl;
}

void resetArr(int arr[], int n)
{
  for (int i = 0 ; i < n ; ++i)
    arr[i] = i+1;
}

int main()
{
  int arr[] = {1,2,3,4,5};
  int n = sizeof(arr)/sizeof(arr[0]), temp;
  
  cout << "\n**********\nPrint original array\n**********\n" << endl;
  printArr(arr, n);

  //make backup
  temp = arr[0];
  //forwards loop
  for (int i = 0 ; i < n-1 ; ++i)
    arr[i] = arr[i+1]; //shift left
  arr[n-1] = temp;

  cout << "\n**********\nShift left with forwards loop\n**********\n" << endl;
  printArr(arr, n);
  resetArr(arr, n);

  //backwards loop
  for (int i = n-2 ; i >= 0 ; --i)
    arr[i] = arr[i+1]; //shift left
  
  cout << "\n**********\nShift left with backwards loop\n**********\n" << endl;
  printArr(arr, n);
  resetArr(arr, n);
  
  //forwards loop
  for (int i = 0 ; i < n-1 ; ++i)
    arr[i+1] = arr[i]; //shift right
  
  cout << "\n**********\nShift right with forwards loop\n**********\n" << endl;
  printArr(arr, n);
  resetArr(arr, n);
  
  //make backup
  temp = arr[n-1];
  //backwards loop
  for (int i = n-2 ; i >= 0 ; --i)
    arr[i+1] = arr[i]; //shift right
  arr[0] = temp;
  
  cout << "\n**********\nShift right with backwards loop\n**********\n" << endl;
  printArr(arr, n);
  resetArr(arr, n);
}
