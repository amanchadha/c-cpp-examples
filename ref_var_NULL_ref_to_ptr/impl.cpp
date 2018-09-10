#include <iostream>

using namespace std;

int main()
{
  {
  //reference to an unitialized pointer
  int *ptr;
  int &ref1 = *ptr;  
  int *&ref2 = ptr;  
  //cout << ref1; //seg fault
  //cout << *ref2; //seg fault
  }

  {
  //reference to an initialized pointer
  int x = 10;
  int *ptr = &x;
  int *&rptr = ptr;
  cout << *rptr << endl; //10
  }

  {
  //reference to NULL
  int *ptr = NULL;
  int &ref1 = *ptr;
  int *&ref2 = ptr;
  //cout << ref1; //seg fault
  //cout << *ref2; //seg fault
  }
}
