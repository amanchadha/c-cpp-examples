#include <iostream>

using namespace std;
/*
class Base
{
  public:
    virtual void test() {}
};
*/
class Base
{
  public:
    virtual void test() = 0;

  private:
    int x;
};

class Derived: public Base
{
  public:
    void test() 
    {
      cout << "In Derived's test" << endl;
    }
};

int main()
{
  //Base object can be created since function is not pure virtual function
  //Base b;
  //b.test();

  //Introduce polymorphism
  Base *b1 = new Derived;
  b1->test();

  return 0;
}
