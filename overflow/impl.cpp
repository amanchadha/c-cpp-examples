#include <iostream> 
#include <math.h>

using namespace std;

//unsigned integer + integer = unsigned integer
int main() 
{ 
  char a = (char) (pow(2, sizeof(char)*8 - 1) - 1);
  cout << "Range of char: -ve: -" << (pow(2, sizeof(char)*8 - 1)) << "\t+ve: " << (pow(2, sizeof(char)*8 - 1) - 1) << endl;
  cout << "Before overflow: " << (int) a << endl;

  //overflow
  a++;
  cout << "Adding in overflow..." << endl;
  cout << "After overflow: " << (int) a << endl;
}

