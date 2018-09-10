#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  cout << "*************\nFLOOR\n*************" << endl; //next lower integer (force round-down)
  cout << floor(3.2) << endl; //3
  cout << floor(3.8) << endl; //3
  cout << floor(-3.2) << endl; //-4
  cout << floor(-3.8) << endl; //-4
  
  cout << "*************\nCEIL\n*************" << endl; //next higher integer (force round-up)
  cout << ceil(3.2) << endl; //4
  cout << ceil(3.8) << endl; //4
  cout << ceil(-3.2) << endl; //-3
  cout << ceil(-3.8) << endl; //-3
}
