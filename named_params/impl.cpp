#include <iostream>

using namespace std;

void test(int x=3, int y=1)
{
  cout << (x-y) << endl; 
}

int main()
{
  int x, y;
  
  test(2, 1);
  test(x=2, y=1);
  test(y=2, x=1);
  cout << y << " " << x << endl;
  test(1, 2);
}
