#include <iostream>

using namespace std;

int func1()
{
  int x = 1;

  return x;
}

int* func2()
{
  int x = 1;

  return &x;
}

int& func3()
{
  static int x = 1;

  return x;
}

int main()
{
  int x = func1();

  cout << x;

  int* y = func2();

  cout << *y;

  int& z = func3();

  cout << z;
}
