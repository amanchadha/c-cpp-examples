#include <stdio.h>

typedef struct
{
  int x;
} s1;

typedef struct s_no_use
{
  int x;
} s2;

typedef struct s3 //typedef requires a name
{
  int x;
};

struct s4
{
  int x;
};

struct
{
  int x;
} s5;

int main(void)
{
  s1 s1_inst;
  s1_inst.x = 100;

  s2 s2_inst;
  s2_inst.x = 200;
  
  //must use 'struct' tag to refer to type 's3'
  struct s3 s3_inst;
  s3_inst.x = 300;
  
  //must use 'struct' tag to refer to type 's4'
  struct s4 s4_inst;
  s4_inst.x = 400;

  s5.x = 500;

  printf("%d\t%d\t%d\t%d\t%d\n", s1_inst.x, s2_inst.x, s3_inst.x, s4_inst.x, s5.x);
}
