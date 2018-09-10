#include <iostream>

using namespace std;

int main(void)
{
  int x = 0, y = 0, z = 0, a;

  a = (x == 0)?(++y):(++z);

  //y should be 1
  cout << y << " " << z << " " << a << endl;
  
  return 0;
}
