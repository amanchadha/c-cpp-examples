#include <iostream>

using namespace std; 

int main()
{
  const int x = 100;
  const int* a = &x;
  int const* b = &x;

  const int c = 1000;
  int const d = 1000;

  cout << *a << *b << endl;
  cout << c << d;
}
