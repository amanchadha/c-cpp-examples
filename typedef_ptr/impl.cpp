#include <iostream>

using namespace std;

typedef struct
{
  int x;
} struct_t, *struct_ptr_t;

typedef int* int_ptr_t;

int main(void)
{
  struct_ptr_t p;
  struct_t struct_inst;
  
  struct_inst.x = 100;

  p = &struct_inst;
  cout << p->x << endl;

  cout << "Struct pointer pointing to an int..." << endl;
  int x = 10;
  p = (struct_ptr_t) &x;
  cout << p->x << endl;
  
  int* p1, p2;
  p1 = &x;
  //p2 = &x;
  cout << *p1 << " " << endl;// << *p2 << endl;
  
  //same as above
  int *p3, p4;
  p3 = &x;
  //p4 = &x;
  cout << *p1 << " " << endl;// << *p4 << endl;
  
  //same as above
  int * p5, p6;
  p5 = &x;
  //p6 = &x;
  cout << *p5 << " " << endl;// << *p6 << endl;
  
  cout << "Type-def'd int pointers..." << endl;
  //solution to the above prob
  int_ptr_t a, b;
  a = &x;
  b = &x;
  cout << *a << " " << *b << endl;
}
