#include <iostream>

using namespace std;

class Base
{
  public:
    virtual void func()
    {
      cout << "Base::func()";
    }

    virtual bool amID1() = 0;
};

class Derived1: public Base
{
  public:
    void func()
    {
      cout << "Derived1::func()";
    }

    virtual bool amID1()
    {
      return true;
    }
};

class Derived2: public Base
{
  public:
    void func()
    {
      cout << "Derived2::func()";
    }

    virtual bool amID1()
    {
      return false;
    }
};

void getObj(Base* b)
{
  //B2D
  if (b->amID1())
    (dynamic_cast<Derived1*>(b))->func();
  else
    (dynamic_cast<Derived2*>(b))->func();
}

int main()
{ 
  //D2B
  Base *b = new Derived1;
  getObj(b);
  
  b = new Derived2;
  getObj(b);
}
