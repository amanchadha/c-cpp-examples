#include <iostream>

using namespace std;

#define MAX(a, b) a > b ? a : b

template <typename T>
T max_t(T a, T b)
{
  return a > b ? a : b;
}

int main(void)
{
  int a = 1, b = 0;

  //using #define
  cout << (MAX(a,b)) << endl;

  //#define side-effects
  cout << (MAX(++a, ++b)) << endl;

  //using templates
  cout << max_t<int>(a, b) << endl;
  cout << max_t(a, b) << endl; //auto type deduction
  
  //b?
  cout << b << endl;
  
  a = 1, b = 0;
  //templates side-effects? nah!
  cout << max_t<int>(++a, ++b) << endl;
}
