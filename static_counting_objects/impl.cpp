#include <iostream>

using namespace std;

class Base
{
  static int count;
  int id;
  public:
    Base()
    {
      count++;
      id = count;
    }

    int getID()
    {
      return id;
    }
};

int Base::count = 0;

int main()
{
  Base b1; //= new Derived;
  Base b2;
  Base b3, b4;

  cout << b1.getID() << endl;
  cout << b2.getID() << endl;
  cout << b4.getID() << endl;
}
