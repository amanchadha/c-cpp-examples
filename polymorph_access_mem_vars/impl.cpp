#include <iostream>

using namespace std;

class Base
{
  public:
    virtual void func()
    {
      cout << "Base::func()" << endl;
    }

    int x;
};

class Derived: public Base
{
  public:
    virtual void func()
    {
      cout << "Derived::func()" << endl;
    }

    int y;
};

int main()
{
  Base *b = new Derived;
  cout << b->x << endl;
  //b->y; //doesnt work
  
  Derived d;
  cout << d.y << endl;
}
