#include <stdio.h>

struct s1
{
   int x; 
   int y;
};

struct s1 s1_inst_g;

int main(void)
{
  struct s2
  {
    int x;  
    int y;
  };

  struct s1 s1_inst;// = {0};
  printf("%d\t%d\n", s1_inst.x, s1_inst.y);

  struct s2 s2_inst;// = {1};
  printf("%d\t%d\n", s2_inst.x, s2_inst.y);
  
  printf("%d\t%d\n", s1_inst_g.x, s1_inst_g.y);
}
