#include <iostream>

using namespace std;

class Base
{
  public:
    virtual void test()
    {
      cout << "Base::test()" << endl;
    }

    virtual void extra()
    {
      cout << "Just another extra!" << endl;
    }

    virtual void overriding_same_sig(int x)
    {
      cout << "Overriding with the same sig Base Int" << endl;
    }

    void non_virt()
    {
      cout << "Non-virtual function in the Base" << endl;
    }
};

class Derived: public Base
//class Derived: private Base
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
    
    void non_virt()
    {
      cout << "Non-virtual function in the Derived" << endl;
    }
 
  /*
    void overriding_same_sig(int x)
    {
      cout << "Overriding with the same sig Derived Int" << endl;
    }
    
*/
    void overriding_same_sig(float x)
    {
      cout << "Overriding with the same sig Derived Float" << endl;
    }
};

int main()
{
  Base *b = new Derived;

  b->test();
  b->extra();
  //b->another(); //cant call since another is not part of Base
  b->overriding_same_sig(1);
  b->overriding_same_sig(1.1);
  
  cout << "******" << endl;
  Derived *d = new Derived;
  d->test();
  d->another();
  d->extra();

  cout << "******" << endl;
  Derived d1;
  d1.another();

  d1.test();

  ((Base) d1).test(); //polymorphism doesnt work w/o pointers -- all specialized features that make it behave like a derived class object are lost -- left with a simple base class object
  //((Base) d1).another(); //slicing problem

  cout << "******" << endl;
  Derived d2;
  Base *b1 = &d2;
  b1->test();
  b1->extra();

  cout << "******" << endl;
  b1->non_virt();
  Derived *d3 = &d2; 
  d3->non_virt();

  return 0;
}
