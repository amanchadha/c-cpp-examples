#include <iostream>

using namespace std;

class Base
{
  public: 
    int x;
    int y;
};

class Derived: public Base
{
  public:
    int y;
    void set_x()
    {
      x = 10;
    }
};

int main()
{
  Derived d;
  d.set_x();
  cout << d.x << endl;
  cout << d.y << "\t" << d.Base::y;
}
