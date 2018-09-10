#include <iostream>

using namespace std;

class Base
{
  public:
    void test() const
    {
      cout << "Base::test()" << endl;
      //x = 10;
    }

    void test1()
    {
      cout << "Base::test1()" << endl;
      x = 10;
    }

    void test2()
    {
      cout << "test2(): Not modifying any data member of the class" << endl;
    }

    Base()
    {
      x = 10;
    }

  private:
    int x;
};

int main()
{
  Base b;
  b.test();
  b.test1();

  const Base b1;
  b1.test();
  //b1.test1(); //const object cant call non-const functions
  
  b1.test2();

  return 0;
}
