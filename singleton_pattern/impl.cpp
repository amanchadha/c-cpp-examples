#include <iostream>

using namespace std;

class S
{
    public:
        static S& getInstance()
        {
            static S    instance;
            return instance;
        }
    
        void disp()
        {
          cout << "Singleton!" << endl;
        }

    private:
        S() {}
        S(S const&);              // Don't Implement.
        void operator=(S const&); // Don't implement
 };

 int main()
 {
  S& s = S::getInstance();
 
  s.disp();
 }
