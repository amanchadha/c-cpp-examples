#include <iostream>
//#define XYZ 7 //same compile time macro

using namespace std;

int main()
{
  #if XYZ == 7
    cout << "Compile time macro defined 1" << endl;
  #endif
  
  #ifdef XYZ
    cout << "Compile time macro defined 2" << endl;
  #endif
  
  #if defined(XYZ)
    cout << "Compile time macro defined 3" << endl;
  #endif
}
