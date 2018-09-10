#include <iostream>

using namespace std;

int global_var;
static int static_var;

int return_non_static()
{
  int x = 7;
  return x;
}

int main()
{
  int local_var;
  register int register_var;

  cout << "Local Variable: ";
  cout << local_var << endl;
  
  cout << "Global Variable: ";
  cout << global_var << endl;
  
  cout << "Static Variable: ";
  cout << static_var << endl;
  
  cout << "Register Variable: ";
  cout << register_var << endl;
  cout << &register_var << endl;
  
  cout << "Return Local Variable: ";
  cout << return_non_static() << endl;
}
