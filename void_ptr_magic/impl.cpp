#include <iostream>

using namespace std;

void pass_me_int_ptr(void* ptr)
{
  int* actual_ptr = (int*) ptr;
  cout << *actual_ptr << endl;
}

void pass_me_char_ptr(void* ptr)
{
  char* actual_ptr = (char*) ptr;
  cout << *actual_ptr << endl;
}

int main(int argc, char** argv)
{
  int x = 10;
  pass_me_int_ptr(&x);
  
  char a = 'A';
  pass_me_char_ptr(&a);
}
