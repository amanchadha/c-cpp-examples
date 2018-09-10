#include <iostream>
#include <assert.h>

using namespace std;

int main(void)
{
  int x, y, z;
  x = y = z = 0;

  cout << "*******" << endl << "x == y == z == 0" << endl << "*******" << endl;
  if (x == y == z == 0) // (x == y) == z == 0 => (1 == z) == 0 => 0 == 0 => 1 (OK)
    cout << "x == y == z == 0: Assignment passed" << endl;
  
  if (x == y == z) // (x == y) == z => 1 == z ==> 0 (NOT OK)
    cout << "x == y == z: Assignment passed" << endl;

  assert(x == y == z == 0); // (x == y) == z == 0 => (1 == z) == 0 => 0 == 0 => 1 (OK)
  
  cout << "*******" << endl << "x == y == z == 1" << endl << "*******" << endl;
  x = y = z = 1;
  assert(x == y == z); // (x == y) == z => 1 == z => 1 == 1 => 1 (OK)

  if (x == y == z == 1) // (x == y) == z == 1 => (1 == z) == 1 => 1 == 1 => 1 (OK)
    cout << "x == y == z == 1: Assignment passed" << endl;
  
  if (x == y == z) // (x == y) == z => 1 == z => 1 == 1 => 1 (OK)
    cout << "x == y == z: Assignment passed" << endl;  
  
  cout << "*******" << endl << "x == y == z == 7" << endl << "*******" << endl;
  x = y = z = 7;  

  if (x == y == z == 7) // (x == y) == z == 7 => (1 == z) == 7 => 0 == 7 => 0 (NOT OK)
    cout << "x == y == z == 7: Assignment passed" << endl;
  
  if (x == y == z)  // (x == y) == z => 0 == z => 0 == 7 => 0 (NOT OK)
    cout << "x == y == z: Assignment passed" << endl;  
  
  x = y = z = 0;  // (x == y) == z => 1 == z => 0 == 0 => 1
  //assert(x == y == z); //assertion failed as (x == y) == z => 1 == z => 1 == 0 => 0 (NOT OK)
}
