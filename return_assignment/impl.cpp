#include <iostream>

using namespace std;

int func()
{
  int x;
  
  return (x = 7);
}
int main()
{
  int x = func();

  cout << x << endl;
}
