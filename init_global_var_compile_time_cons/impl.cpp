#include <iostream>
#include <math.h>

using namespace std;

int func(int x)
{
  return x;
}

int x = 10;
int y = x*x;
int z = x*x*sizeof(int);
int a = ceil(3.2);
int b = func(10);

int main(void)
{
  cout << x << " " << y << " " << z << " " << a << " " << b << endl;
}
