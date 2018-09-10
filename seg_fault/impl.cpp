#include <iostream>

using namespace std;

class Base
{
  int y; //private

  public:
    int x[100];
};

int main()
{
  Base *b;
  int x[100];
  cout << x[900009];
  //cout << b->x[99];// << b->y;
}
