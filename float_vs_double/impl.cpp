#include <iostream>

using namespace std;

void func(int)
{
  cout << "int" << endl;
}

void func(float)
{
  cout << "float" << endl;
}

void func(double)
{
  cout << "double" << endl;
}

int main(void)
{
  float f = 10.0f;
  float f1 = 10.0;
  double d = 10;

  cout << "Function call check..." << endl;
  func(f);  
  func(f1);
  func(d);

  cout << "Overloading check..." << endl;
  func(10); //int
  func(10.0f); //float
  func(10.0); //double
}
