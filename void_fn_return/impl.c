#include <stdio.h>
#include <stdint.h>

void test()
{
  static int x;
  int y;
  if (x == 0)
    return;

  return;
}

int main(int argc, char** argv)
{
  test();

  printf("I'm done\n");
}
