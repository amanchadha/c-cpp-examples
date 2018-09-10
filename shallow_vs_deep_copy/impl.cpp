#include <iostream>

using namespace std;

class Base
{
  public:
  Base(int x): x(x) {}

  int x;
};

int main()
{
  int x = 10;
  int y = 10;

  string s1 = "hey";
  string s2 = "hey";

  int *arr1 = new int; arr1[0] = 0;
  int *arr2 = new int; arr2[0] = 1;

  Base b1(10);
  Base b2(100);

  //shallow copy
  x = y; //shallow copy is the same as a deep copy for primitive types
  arr1 = arr2; //shallow copy as arr1 points to the first element of the array
  b1 = b2; //shallow copy as the = operator is not overloaded 

  //deep copy
  s1 = s2; //will do a deep copy as the = operator has been overloaded for C++ strings within the std::string class

  //compare arrays
  cout << "**********" << endl;
  cout << "Array compare" << endl;
  cout << &arr1[0] << "\t" << &arr2[0] << endl; //should be the same
  cout << arr1 << "\t" << arr2 << endl; //should be the same
  cout << &arr1 << "\t" << &arr2 << endl; //should NOT be the same

  //compare strings
  cout << "**********" << endl;
  cout << "String compare" << endl;
  cout << "Value equality: " << (s1 == s2) << endl; //same
  cout << "Address equality: " << (&s1 == &s2) << endl; //not same
  
  //compare objects
  cout << "**********" << endl;
  cout << "Object compare" << endl;
  cout << "Value equality: " << (b1.x == b2.x) << endl; //same
  cout << "Address equality: " << (&b1 == &b2) << endl; //not same
}
