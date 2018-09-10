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

class Derived: private Base
{
  public:
    /*virtual*/ void test()
    {
      cout << "Derived::test()" << endl;
    }

    void another()
    {
      cout << "Derived::another()" << endl;
    }
};

int main()
{
  Base *b = new Derived;

  b->test();
  //b->another(); //cant call since another is not part of Base
  
  Derived *d = new Derived;
  d->another();

  return 0;
}
