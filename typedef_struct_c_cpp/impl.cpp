#include <iostream>

using namespace std;

typedef struct
{
  int x;
} s1;

typedef struct s_no_use
{
  int x;
} s2;

struct s3
{
  int x;
};

struct
{
  int x;
} s4;

int main(void)
{
  s1 s1_inst;
  s1_inst.x = 100;

  s2 s2_inst;
  s2_inst.x = 200;
  
  s3 s3_inst;
  s3_inst.x = 300;
  
  s4.x = 400;
  
  cout << s1_inst.x << " " << s2_inst.x << " " << s3_inst.x << " " << s4.x << endl;
}
