#include <iostream>

using namespace std;

class Base
{
  public:
    void test(int x)
    {
      cout << "Base::test(int): " << x << endl;
    }
    
    void test(float x)
    {
      cout << "Base::test(float): " << x << endl;
    }
    
    void test(double x)
    {
      cout << "Base::test(double): " << x << endl;
    }
};

int main()
{
  Base b;

  b.test(10);

  b.test(10.1f);
  
  b.test(10.1);
}
