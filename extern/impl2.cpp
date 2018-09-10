#include <iostream>

using namespace std;

extern int global;
//extern int local;

int main()
{
  cout << global;
  //cout << local;
}
