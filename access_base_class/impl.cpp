#include <iostream>

using namespace std;

class Base
{
public:
   void func()
   {
     cout << "In Base" << endl;
   }
};

class Derived: public Base
{
public:
   void func()
   {
     cout << "In Derived" << endl;
   }
};

int main()
{
  Derived d;
  d.func();
  d.Base::func();

  Derived *d1 = new Derived;
  d1->Base::func();
}
