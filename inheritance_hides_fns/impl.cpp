#include <iostream>

using namespace std;

class Base 
{
  public:
    /*virtual void f(int x)
    {
      cout << "f(int) in Base" << endl;
    }*/

    virtual void f(double x)
    {
      cout << "f(double) in Base" << endl;
    }
    
    static void testme()
    {
      cout << "Static in Base" << endl;
    }
};

class Derived: public Base 
{
  public:
    virtual void f(double *pd)
    {
      cout << "f(double*) in Derived" << endl;
    }

    virtual void f(int x)
    {
      cout << "f(int) in Derived" << endl;
    }

    /*virtual void f(double x)
    {
      cout << "f(double) in Derived" << endl;
    }*/
};

int main()
{
  Derived *pd = new Derived;
  pd->f(10.1);
  // error!
  
  Base *b = new Derived;
  b->f(10.1);

  //calling static function
  Base::testme();
  b->testme();
  pd->testme();
  Derived::testme();
}
