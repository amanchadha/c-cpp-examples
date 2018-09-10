#include <iostream>

using namespace std;

class Base
{
  public:
    int x;

    Base()
    {
      cout << "Default CTor" << endl;
    }
    
    void func()
    {
      cout << "In func" << endl;
    }
};

void fun()
{
  cout << "OK" << endl;
}

int main(void)
{
  Base b1;
  
  b1.func();

  fun();
}
