#include <iostream>

using namespace std;

class Base
{
  public:
    int x; 

    Base()
    {
      x = 10;
    }
};

Base& return_handle_to_local_obj()
{
  Base b;

  return b;
}

Base* test()
{
  Base *b;

  return b;
}

Base* return_handle_to_heap_obj()
{
  Base *b = new Base;

  return b;
}

char* return_char_ptr()
{
  char *x = "Hi"; 

  return x;
}

char* return_char_arr()
{
  char x[] = "Hi"; 

  return x;
}

int main()
{
  cout << "Returning handle to local object (wrong)..." << endl;
  Base& b = return_handle_to_local_obj();
  cout << b.x << endl;

  cout << "Returning handle to heap object (right)..." << endl;
  Base* b1 = return_handle_to_heap_obj();
  cout << b1->x << endl;
  
  cout << "Returning char pointer..." << endl;
  char *str = return_char_ptr();
  cout << str[0] << str[1] << endl;
  
  cout << "Returning char array..." << endl;
  char *str1 = return_char_arr();
  cout << str1 << endl;

  test();
}
