#include <iostream>
#include <assert.h>

using namespace std;
  
int main(void)
{
struct s
{
  int x;
};

  s *x = new s;
  cout << x->x;
}

