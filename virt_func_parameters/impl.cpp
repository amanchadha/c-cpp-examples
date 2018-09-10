#include <iostream>

using namespace std;

class Base
{
  public:
    virtual void test()
    {
      cout << "Base::test()" << endl;
    }
};

class Derived: public Base
{
  public:
    virtual void test()
    {
      cout << "Derived::test()" << endl;
    }
};

class MostDerived: public Derived
{
  public:
    /*virtual*/ void test()
    {
      cout << "MostDerived::test()" << endl;
    }
};

int func(Base *b)
{
  b->test();
}

int func1(Base b)
{
  b.test();
}

int main()
{
  Derived d;

  func(&d);

  MostDerived md;

  func(&md);

  func1(d);

  func1(md);

  return 0;
}
