#include <iostream>
#include <assert.h>

using namespace std;
  
void while_loop_break()
{
  while (1)
  {
    //break;
    return;  
  }
}

void for_loop_break()
{
  for (;;)
  {
    break;
    //return;  
  }
}

int main(void)
{
  //while_loop_break();  
  for_loop_break();  
}
