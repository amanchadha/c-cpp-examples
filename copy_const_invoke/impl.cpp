#include<iostream>

using namespace std;

class Base
{
  public:
  Base()
  {
    cout << "In Normal Constructor of Base" << endl;
  }

  Base(int x)
  {
    cout << "In Overloaded Constructor of Base" << endl;
    this->x = x;
  }

  Base(const Base& rhs)
  {
    cout << "In Copy Constructor of Base" << endl;
  }

  ~Base()
  {
    cout << "In Destructor of Base" << endl;
  }

  void operator=(const Base& rhs)
  {
    cout << "In Assignment Operator of Base" << endl;
  }
  
  virtual void BaseFn()
  {
    cout << "Base::BaseFn" << endl;
  }

  private:
  int x;
};

//check if copy ctor is called when a derived object is used to init a base class object
class Derived: public Base
{
  public:
    Derived()
    {
      cout << "In Normal Constructor of Derived" << endl;
    }

    Derived(const Derived& rhs)
    {
      cout << "In Copy Ctor of Derived" << endl;
    }
  
  void DerivedFn()
  {
    cout << "Derived::DerivedFn" << endl;
  }
  
  virtual void BaseFn()
  {
    cout << "Derived::BaseFn" << endl;
  }

  int d;
};

int main()
{

  Base b1;
  Base b2(b1);
  Base b3 = b1;
  Base *b4;
  *b4 = b1;
  Base b5 = 10;

  cout << "******" << endl;
  Derived d;
  Base b6(d); //same as Base
  b6.BaseFn();
  //b6.DerivedFn(); //doesnt work

  cout << "******" << endl;
  Base *b7 = new Derived();
  b7->BaseFn(); //polymorphed
  //b6.DerivedFn();
  
  cout << "******" << endl;
  Derived *d1 = (Derived *) new Base(); //same as Derived
  d1->DerivedFn(); 
  d1->BaseFn();
  cout << "******" << endl;
  
  cout << "******" << endl;
  //Derived d3(b1); //doesnt work
  Base *b8 = new Base();
  Derived *d2 = dynamic_cast<Derived*>(b8); //same as Derived
  d2->DerivedFn(); 
  d2->BaseFn();
  cout << "******" << endl;
}
