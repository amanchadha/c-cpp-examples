#include <iostream>

#define SIZEOF(Foo) ((char*) &Foo[1] - (char*) &Foo[0])

using namespace std;

typedef struct Foo {
   char x ;  // 1 byte
   int y ;   // 4 byte, must be word-aligned
   char z ;  // 1 byte
   int w ;   // 4 byte, must be word-aligned
   //total: 10 -- however its 16 (1+3+4+3+1+4)
} Foo;

int main()
{
  cout << sizeof(Foo) << endl;

  Foo f[2];
  cout << SIZEOF(f);
}
