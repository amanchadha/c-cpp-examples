#if 0
#include <iostream>

using namespace std;

class Base
{
  private:
  
  public:
    static int x;
    static int test()
    {
      cout << "Base::test()" << endl;
      return x;//x = 10;
    }
};

int main()
{
  Base::test();

  return 0;
}

#endif

#include <iostream>
 
using namespace std;

class Base
{
   static int objectCount;
   public:
      Base()
      {
        objectCount++;
      }
      static int getCount()
      {
         return objectCount;
      }
};


// Initialize static member of class Box
int Base::objectCount = 0;

int main(void)
{  
   // Print total number of objects before creating object.
   cout << "Inital Stage Count: " << Base::getCount() << endl;

   Base Box1;
   Base Box2;

   // Print total number of objects after creating object.
   cout << "Final Stage Count: " << Base::getCount() << endl;

   return 0;
}
