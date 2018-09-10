#include <iostream>

using namespace std;

int main()
{
  int x[] = {1,2};
  int y[] = {3,4};

  copy(x, x+2, y);
  cout << y[0] << "\t" << y[1] << endl;

  memset(y, 0, 2*sizeof(int));
  cout << y[0] << "\t" << y[1] << endl;

  memcpy(y, x, 2*sizeof(int));
  cout << y[0] << "\t" << y[1] << endl;
  
  memset(y, 0, 2*sizeof(int));
  memmove(y, x, 2*sizeof(int));
  cout << y[0] << "\t" << y[1] << endl;
}
