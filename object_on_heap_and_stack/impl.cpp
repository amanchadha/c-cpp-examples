#include <iostream>

using namespace std;

class Base
{
  public:
    int x;
    Base()
    {
      cout << "Normal Constructor called!" << endl;
      x = 10;
    }
    Base(int a)
    {
      cout << "Overloaded Constructor called!" << endl;
      x = a;
    }
};

int main()
{
  //on stack
  //Base b(); //-- DOESNT WORK
  //cout << "******" << endl;
  //cout << b.x << endl;
  
  //on stack
  Base b1;
  cout << "******" << endl;
  cout << b1.x << endl;

  //on stack
  Base b2(10); //-- DOESNT WORK
  cout << "******" << endl;
  cout << b2.x << endl;

  //on heap
  Base *b3 = new Base(20);
  cout << "******" << endl;
  cout << b3->x << endl;
  
  //on heap
  Base *b4 = new Base;
  cout << "******" << endl;
  cout << b4->x << endl;

  //on stack -- part 2
  cout << "******" << endl;
  cout << (Base()).x;
  
  //on heap -- part 2
  cout << "******" << endl;
  cout << (new Base())->x;
  
  return 0;
}
