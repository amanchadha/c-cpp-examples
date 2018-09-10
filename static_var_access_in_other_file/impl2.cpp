#include <iostream>

using namespace std;

extern int *ptr_x, *ptr_y;
//extern int x, y; //doesnt work

int main()
{
  cout << *ptr_x << " " << *ptr_y << endl;
}
