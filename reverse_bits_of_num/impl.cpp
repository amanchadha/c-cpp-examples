#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
  unsigned int x = pow(2,sizeof(unsigned int)*8)-1; //= 1;
  unsigned int x_dup = 0;
  unsigned int x_rev = 0;

  int y = 256;
  int y_rev_digits = 0;
  
  //reverse bits of a number
  for (int i = 0; i < sizeof(x)*8; i++)
  {
    //cout << sizeof(int) << endl;
    x_dup |= (x & (1 << i));
    //x_rev |= (x & (1 << ((sizeof(x)*8 - 1) - i))) >> (sizeof(x)*8 - 1 - i);

    if (x & (1 << i))
        x_rev |= (1 << ((sizeof(x)*8 - 1) - i));    
  }

  cout << x_dup << "\t" << x_rev << endl;

  //reverse a number, i.e., reverse the digits of a number
  while(y)
  {
    y_rev_digits = y_rev_digits*10 + (y%10);
    y /= 10;
  }

  cout << y << "\t" << y_rev_digits << endl;
}
