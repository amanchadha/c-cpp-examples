#include <iostream>

using namespace std;
  
int main()
{
  volatile const int x = 100;
  int* ptr = (int *) &x;
  *ptr = 200;
  cout << x << endl;

  //second way -- cast away the constness
  int& y = const_cast<int&>(x);
  y = 300;
  cout << x << endl;
}
