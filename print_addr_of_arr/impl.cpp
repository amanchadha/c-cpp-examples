#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
  int x[100];

  cout << x << "\t" << &x[0] << "\t" << &x << endl;
  
  int* y = new int[100];

  cout << y << "\t" << &y[0] << "\t" << &y << endl;
}
