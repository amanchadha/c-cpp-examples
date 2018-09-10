#include <stdio.h>

//using namespace std;
/*
class Base
{
  private:
    int count;
};
*/

char *aa = "Hey"; 
char bb[] = "Hey"; 

int main()
{
  //Base b1;
  //Base *b2 = new Base;
  bb[0] = 'Z';
  //aa[0] = 'Z';

  int x;

  char *a = "Hey"; 
  char a1[] = "Hey"; 
  char *a2;

  int y,z;

  //cout << sizeof(b1) << " " << sizeof(int) << " " << &b1 << " " << &b2 << " " << &x << endl;
  //printf("%d %d %p %p %p, sizeof(b1), sizeof(int), &b1, &b2, &x);
  
  //cout << &a << " " << &a1 << endl;
  printf("%p %p %p %p %p %s\n", &a, &a1, &aa, &bb, &a2, a);
}
