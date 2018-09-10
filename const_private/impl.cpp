#include <iostream>

using namespace std;

class Base
{
  private:
    Base()
    {
      cout << "Base Constructor" << endl;
    }
  
  public:
    Base(int a)
    {
      cout << "Overloaded Base Constructor" << endl;
    }
};

int main()
{
  //Base b;

  Base b2(10);

  return 0;
}
