#include <iostream>

using namespace std;

class Base
{

};

int func(int x)
{
  return x;
}

int main()
{
  int x;

  if (x = func(1))
    cout << "Got it" << endl;
  else
    cout << "Didn't get it" << endl;
  cout << x << endl;
  
  if (x = func(0))
    cout << "Got it" << endl;
  else
    cout << "Didn't get it" << endl;
  cout << x << endl;

  if (func(1))
    cout << "Got it" << endl;
  else
    cout << "Didn't get it" << endl;
  
  if (func(0))
    cout << "Got it" << endl;
  else
    cout << "Didn't get it" << endl;

  return 0;
}
