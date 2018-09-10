#include <iostream>

using namespace std;

class Base
{
  public:
    void test1()
    {
      this->test();
      test();
    }

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

int main()
{
  Base *b = new Derived;

  b->test();
  b->test1();

  Derived *d = new Derived;

  d->test();
  d->test1();
}
