#include <iostream>

void foo(int a, int b)
{
    printf("%d", a);
    //return;
}

int main()
{
  foo(2, 3);
  int z;

  void foo(int a, int b = 5); // redeclare
  foo(z=8); // OK, calls `foo(8, 5)`

  void foo(int a = 1, int b); // redeclare again
  foo(); // OK, calls `foo(1, 5)`

  foo(2); // OK, calls `foo(2, 5)`
}
