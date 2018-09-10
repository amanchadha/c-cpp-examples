#include <iostream>
//#define ABC //same compile time macro

using namespace std;

int main()
{
  #ifdef ABC
    cout << "Compile time macro defined 1" << endl;
  #endif
  
  //same as above
  #if ABC == 1
    cout << "Compile time macro defined 2" << endl;
  #endif
  
  #if ABC
    cout << "Compile time macro defined 2" << endl;
  #endif
  
  #if defined(ABC) && defined(DEF)
    cout << "Compile time macro defined 3" << endl;
  #endif
}
