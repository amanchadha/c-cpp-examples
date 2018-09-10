#include <iostream>

using namespace std;

class Base
{
  public:
    virtual void test()
    {
      cout << "Base::test()" << endl;
    }

    ///*virtual*/ ~Base()
    virtual ~Base()
    {
      cout << "In Base's Destructor" << endl;
    }

    Base()
    {
      cout << "In Base's Constructor" << endl;
    }
};

class Derived: public Base
{
  public:
    /*virtual*/ void test()
    {
      cout << "Derived::test()" << endl;
    }

    ~Derived()
    {
      cout << "In Derived's Destructor" << endl;
    }
    
    Derived()
    {
      cout << "In Derived's Constructor" << endl;
    }
};

class MostDerived: public Derived//Base
{
  public:
    void test()
    {
      cout << "MostDerived::test()" << endl;
    }

    MostDerived()
    {
      cout << "In MostDerived's Constructor" << endl;
    }
    
    ~MostDerived()
    {
      cout << "In MostDerived's Destructor" << endl;
    }
};

int main()
{
  {
    Base *b = new MostDerived; //Derived;

    b->test();

    delete b;
  }

  cout << "*****" << endl;
  
  {
    Base *b = new Derived;

    b->test();
    
    delete b;
  }

  cout << "*****" << endl;

  {
    Derived *d = new MostDerived;

    d->test();

    delete d;
  }
  
  return 0;
}
