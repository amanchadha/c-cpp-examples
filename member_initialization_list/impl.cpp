#include <iostream>

using namespace std;

class Base
{
public:
   Base(int foo) : mFoo(foo)
   { 
    cout << "Int Constructor: " << foo;
   }
   
   Base(float a) : x(a)
   { 
    cout << "Float Constructor: " << x;
   }
   
   /*
   Base(float x)
   { 
    this->x = x;
    cout << "Float Constructor: " << x;
   }
   */

private:
   int mFoo;
   float x;
};

int main()
{
  Base *x = new Base(10);
}
