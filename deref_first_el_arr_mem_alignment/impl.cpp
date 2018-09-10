#include <iostream>

using namespace std;

int main()
{
  int arr[10] = {0};
  char ca[2] = {'a', 'b'};

  arr[0]++;

  cout << "First el of arr" << endl;
  cout << &arr[0] << " " << &arr << " " << arr << " " << *arr << endl;

  cout << "Alignment checking..." << endl;
  cout << &arr[0] << " " << &arr[1] << endl;

  cout << "Alignment checking..." << endl;
  printf("%p %p", &ca[0], &ca[1]);

  return 0;
}
