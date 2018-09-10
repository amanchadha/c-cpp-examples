#include <iostream>

using namespace std;

int main()
{
  int x; 
  int y;
  char a, b;
  int arr[100];
  struct st
  {
    int x;
    char a;
    char b;
    int y;
  } s;
  
  cout << "x: " << &x << "\ty: " << &y << endl;
  printf("a: %p\tb: %p\n", &a, &b);
  cout << "arr[0]: " << &arr[0] << "\tarr[1]: " << &arr[1] << endl;
  printf("s.x: %p\ts.a: %p\ts.b: %p\ts.y: %p\n", &s.x, &s.a, &s.b, &s.y);
  printf("sizeof(s.x): %d\tsizeof(s.a): %d\tsizeof(s.b): %d\tsizeof(s.y): %d\tsizeof(s): %d\n", sizeof(s.x), sizeof(s.a), sizeof(s.b), sizeof(s.y), sizeof(s));

  //misaligned accesses
  cout << "Misaligned access" << endl;
  int* int_ptr = (int *) &s.a;
  printf("s.a: %p\tint_ptr: %p\n", &s.a, &int_ptr);
}
