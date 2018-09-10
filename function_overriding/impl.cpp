#include <iostream>

using namespace std;

class Base
{
  public:
    void test()
    {
      cout << "Base::test()" << endl;
    }
};

class Derived
{
  public:
    void test()
    {
      cout << "Derived::test()" << endl;
    }
};

int main()
{
  Base b;
  b.test();

  Derived d;
  d.test();

  return 0;
}
