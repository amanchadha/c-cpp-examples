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

class Derived1: public Base
{
  public:
    virtual void func()
    {
      cout << "Derived1::func()" << endl;
    }
};

class Derived2: public Base
{
  public:
    virtual void func()
    {
      cout << "Derived2::func()" << endl;
    }
};

void acceptsAllBaseObjs1(Base& obj)
{
  obj.func();
}

void acceptsAllBaseObjs2(Base* obj)
{
  obj->func();
}

int main()
{
  Base* b[3];

  b[0] = new Base();
  b[1] = new Derived1();
  b[2] = new Derived2();

  for (int i = 0 ; i < sizeof(b)/sizeof(b[0]) ; ++i)
  {
    acceptsAllBaseObjs1(*b[i]);
    acceptsAllBaseObjs2(b[i]);
  }
}
