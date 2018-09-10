#include <iostream>

using namespace std;

int func()
{
  int x;

  return (x = 7);
}

int main()
{
  int x;
  cout << x << endl;
  cout << x = func() << endl;
  cout << x << endl;
  
  x = func();
  cout << x << endl;

  x = 0;
  if (x = 0) 
    cout << "x = 0" << endl;     
  else if (x == 1) //x = 1 is ALWAYS going to be true as (x = 1) returns back the value assigned, i.e., 1, and since the other conditionals are else ifs, they wont be evaluated at all, otherwise they would be true too.
    cout << "x = 1" << endl;     
  else if (x = -1)
    cout << "x = 0" << endl;     

  x = 0;
  if (!x) //only if x is 0
    cout << "YES!" << endl;
  if (x) //only if x is anything else apart from 0
    cout << "NO!" << endl;

  x = -1;
  if (x) //-1 also works
    cout << "YES!" << endl;
}
