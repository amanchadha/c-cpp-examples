#include <iostream>

using namespace std;

class Base1
{
  public:
  int x;
  Base1()
  {
    cout << "Base1 Default CTor Called" << endl;
  }
  Base1(int x)
  {
    this->x = x;
    cout << "Base1 Parameterized CTor Called" << endl;
  }
  Base1(const Base1& rhs)
  {
    this->x = rhs.x;
    cout << "Base1<->Base1 Copy CTor Called" << endl;
  }
  void operator=(const Base1& rhs)
  {
    x = rhs.x;
    cout << "Base1<->Base1 assignment operator called" << endl;
  }
};

class Base2
{
  Base1 x;

  public:
  //Base(Base x): x(x) {}
  Base2()
  {
    cout << "Base2 CTor" << endl;
  }
  /*
  Base2(const Base2& rhs)
  {
    this->x = rhs.x;
    cout << "Base2<->Base2 Copy CTor Called" << endl;
  }*/
  Base2(Base1 rhs)//:x(rhs)
  {
    x = rhs;
    cout << "Base2<->Base1 Ctor Called" << endl;
  }
};

int main()
{
  Base1 b1;
  cout << "******" << endl;
  Base2 b2(b1);
}
