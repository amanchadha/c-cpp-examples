#include <iostream>

using namespace std;

struct s1
{
   int x;  
};

s1 s1_inst_g;

int main(void)
{
  struct s2
  {
    int x;  
  };

  s1 s1_inst;
  cout << s1_inst.x << endl;

  s2 s2_inst;
  cout << s2_inst.x << endl;
  cout << s1_inst_g.x << endl;
}
