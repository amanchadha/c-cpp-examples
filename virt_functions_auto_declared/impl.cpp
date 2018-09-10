#include <iostream>

using namespace std;

class Base
{
  public:
    virtual void inBaseAndDerived()
    {
      cout << "Base::test()" << endl;
    }

    virtual void inBaseAndDerivedAndMostDerived()
    {
      cout << "Base::inBaseAndDerivedAndMostDerived()" << endl;
    }

    void onlyBase()
    {
      cout << "Base::onlyBase()" << endl;
    }

    void nonVirtualInBaseAndDerived()
    {
      cout << "Base::nonVirtualInBaseAndDerived()" << endl;
    }    
};

class Derived: public Base
{
  public:
    /*virtual*/ void inBaseAndDerived()
    {
      cout << "Derived::inBaseAndDerived()" << endl;
    }

    void inBaseAndDerivedAndMostDerived()
    {
      cout << "Derived::inBaseAndDerivedAndMostDerived()" << endl;
    }    

    virtual void notInBase()
    {
      cout << "Derived::notInBase()" << endl;
    }

    void nonVirtualInBaseAndDerived()
    {
      cout << "Derived::nonVirtualInBaseAndDerived()" << endl;
    }    
};

class MostDerived: public Derived
{
  public:
    void inBaseAndDerivedAndMostDerived()
    {
      cout << "MostDerived::inBaseAndDerivedAndMostDerived()" << endl;
    } 

    void notInBase()
    {
      cout << "MostDerived::notInBase()" << endl;
    }
};

int main()
{
  Base *b1 = new Derived;
  b1->inBaseAndDerived();
  b1->onlyBase();
  b1->nonVirtualInBaseAndDerived();

  cout << "******" << endl;
  Base *b2 = new MostDerived;
  b2->inBaseAndDerived();
  
  cout << "******" << endl;
  //Base *b3 = new MostDerived; //ERROR: no member named 'notInBase' in 'Base'
  Derived *d = new MostDerived;
  d->notInBase();

  cout << "******" << endl;
  Base *b3 = new MostDerived;
  b3->inBaseAndDerivedAndMostDerived();  
  b3->inBaseAndDerived();  

  return 0;
}
