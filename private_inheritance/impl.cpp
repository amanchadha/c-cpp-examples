#include <iostream>

using namespace std;

class Base
{
  public:
    virtual void test()
    {
      cout << "Base::test()" << endl;
    }

    void extra()
    {
      cout << "Base::extra()" << endl;
    }
};

class Derived: private Base
{
  public:
    virtual void test()
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
  Derived d1;
  d1.another();

  d1.test();

  //d1.extra(); //extra is a private member of base

  ((Base) d1).test(); //polymorphism doesnt work w/o pointers -- all specialized features that make it behave like a derived class object are lost -- left with a simple base class object
  //((Base) d1).another(); //slicing problem
  
  //Base *b1 = new Derived(); //not OK!
  //b1->test();

  return 0;
}
