#include <iostream>

using namespace std;

int arr1[2] = {1};
//int arr2[2][2] = {{0, 1}, {2, 3}};
int arr2[2][2] = {0};
int arr3[2][2] = {{0}};
int arr4[2][2][2] = {0};
int arr5[][2][2] = {0};

int main(void)
{
  cout << arr1[0] << endl;
  cout << arr2[0][1] << endl;
  cout << arr3[0][1] << endl;
  cout << arr4[0][1][1] << endl;
  cout << arr5[2][1][1] << endl;
}
