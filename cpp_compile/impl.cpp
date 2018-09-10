#include <iostream>

using namespace std;

class Base
{
  public:
    virtual void test()
    {
      cout << "Base::test()" << endl;
    }

    /*virtual*/ ~Base()
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

    void another()
    {
      cout << "Derived::another()" << endl;
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
  cout << "*****" << endl;
  cout << "Virtual Functions" << endl;
  cout << "*****" << endl;

  {
    Base *b = new MostDerived;

    //b->test();

    //b->~Base();
    
    delete b;
  }

  cout << "*****" << endl;
  
  {
    Base *b = new Derived;

    //b->test();

    //b->~Base();
    
    delete b;
  }

  cout << "*****" << endl;
  
  Base *b = new Base;

  delete b;
 
  cout << endl << endl;
  cout << "*****" << endl;
  cout << "Standard Inherited Functions" << endl;
  cout << "*****" << endl;

  {
    MostDerived *b = new MostDerived;

    //b->test();

    //b->~Base();
    
    delete b;
  }

  cout << "*****" << endl;
  
  {
    Derived *b = new Derived;

    //b->test();

    //b->~Base();
    
    delete b;
  }

  {
    cout << "*****" << endl;
  
    Base *b = new Base;

    delete b;
  }

  return 0;
}
