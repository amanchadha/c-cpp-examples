#include <iostream>

using namespace std;

class BlankBase
{
};

struct BlankStruct
{
};

class FilledBase
{
  int x;
};

struct FilledStruct
{
  int x;
};

int main(void)
{
  BlankBase b;
  BlankStruct s;
  
  FilledBase fb;
  FilledStruct fs;

  cout << "Sizeof blank struct and blank class..." << endl;
  cout << sizeof(b) << " " << sizeof(s) << endl;
  
  cout << "Sizeof filled struct and filled class..." << endl;
  cout << sizeof(fb) << " " << sizeof(fs) << endl;
}
