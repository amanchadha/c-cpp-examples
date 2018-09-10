#include <iostream>

using namespace std;

class Base
{
  public:
  int x;
  
  Base()
  {
    cout << "Base Default CTor" << endl;
  }
  
  Base(int a)
  {
    x = a;
    cout << "Base Parameterized CTor" << endl;
  }
  
  Base(const Base& rhs)
  {
    cout << "Base Copy CTor" << endl;
  }
  
  Base& operator=(const Base& rhs)
  {
    cout << "Base Assignment Op" << endl;
  }
};

int main(void)
{
  Base b1; //default ctor
  Base b2(10); //param ctor

  Base b3 = b1; //copy ctor
  cout << b3.x << " " << b2.x << endl;
  b3 = b2; //assignment op
  cout << b3.x << endl;
}
