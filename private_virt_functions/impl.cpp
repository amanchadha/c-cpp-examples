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

class Derived: public Base
{
  //public:
  private:
    void test()
    {
      cout << "Derived::test()" << endl;
    }
};

int main()
{
  Base *b = new Derived;  

  b->test();
}
