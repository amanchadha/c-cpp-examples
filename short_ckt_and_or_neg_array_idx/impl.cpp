#include <iostream>

using namespace std;

int main()
{
  char x = 'A';
  int arr[100];

  arr[-1] = 7; //works!

  cout << arr[0] << " " << arr[-1] << endl;

  int i = -1;
  if (i > 0 && arr[i]++ == 7) //short circuited
    cout << "Not Short circuited" << endl;
  
  cout << arr[i] << endl;

  if (i < 0 && arr[i]++ == 7)
  {}
  
  cout << arr[i] << endl;

  cout << "";
  
  if (i < 0 || arr[i]++ == 7) //short circuited
    cout << "Short circuited" << endl;
  
  cout << arr[i] << endl;

  if (i > 0 || arr[i]++ == 7)
  {}
  
  cout << arr[i] << endl;

  cout << arr[100] << endl; //works too!
}
