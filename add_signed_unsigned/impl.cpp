#include <iostream> 
#include <iomanip>
#include <math.h>

using namespace std;

//unsigned integer + integer = unsigned integer
int main() 
{ 
  unsigned int a = ((unsigned int) (pow(2, sizeof(int)*8 - 1) - 1) + (pow(2, sizeof(int)*8 - 1))) ;
  cout << "Range of unsigned (method 1): " << setprecision(10) << (pow(2, sizeof(int)*8 - 1)) + (pow(2, sizeof(int)*8 - 1) - 1) << endl;
  cout << "Range of unsigned (method 2): " << setprecision(10) << pow(2, sizeof(int)*8) - 1 << endl;
  int b = (int) (pow(2, sizeof(int)*8 - 1) - 1);
  cout << "Range of signed: -ve: -" << (pow(2, sizeof(int)*8 - 1)) << "\t+ve: " << (pow(2, sizeof(int)*8 - 1) - 1) << endl;

  a = 10000000;
  cout << a << "\t" << b << endl;
  cout << a+b << endl; 

  a = 1;
  b = -2;
  cout << a+b << endl; 
}
