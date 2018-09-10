#include <iostream>

using namespace std;

int main()
{
  string a = "hey there";
  char b = 'x';

  a[0] = 'c';
  a[1] = b;
  cout << a << a[0] << endl;
}
