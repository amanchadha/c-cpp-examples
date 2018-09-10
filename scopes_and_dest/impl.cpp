#include <iostream>

using namespace std;

class Base
{
  public:
    ~Base()
    {
      cout << "Base destructor" << endl;
    }
};

Base& test1()
{
  Base *b = new Base;

  return *b;
}

void test2()
{
  Base b;//*b = new Base;
}

int main()
{
  //new scope
  {
    Base b1 = test1();
  }

  cout << "Destructor for b1 should be called before this line..." << endl;

  {
    Base b1 = test1();
    cout << "Destructor for b1 should be called after this line..." << endl;
  }

  Base b2;

  Base b1 = test1();

  cout << "test2()" << endl;
  test2();

  Base *b3 = new Base();
  delete b3;
}
