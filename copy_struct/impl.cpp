#include <iostream>

using namespace std;

struct st
{
  int x, y;
};

int main(void)
{
  st s1, s2;
  s1.x = 0; s1.y = 1;
  cout << s1.x << " " << s1.y << endl;

  s2.x = 2; s2.y = 3;
  cout << s2.x << " " << s2.y << endl;
  
  s2 = s1;
  cout << s2.x << " " << s2.y << endl;
}
