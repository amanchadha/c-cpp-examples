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
//class Derived: private Base
{
};

int main()
{
  Base *b = new Derived;

  b->test();

  Derived *d = new Derived;

  d->test();
}
