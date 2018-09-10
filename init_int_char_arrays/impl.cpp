#include <iostream>

using namespace std;

void func(char* a, char* b, char* c, char* d)
{
   cout << a << " " << b << " " << c << " " << d << endl;
}

int main()
{
   int x[] = {1,2,3};
   int *y = x;
   int z[3] = {1,2,3};
   //int *f = {1,2,3}; 
   cout << x[0] << " " << y[0] << " " << z[0] << endl;

   char *a = "Hi";
   char b[] = "Hi";
   char c[3] = "Hi";
   //char *d = {'H', 'i', '\0'};
   char d[3] = {'H', 'i', '\0'};
   cout << a << " " << b << " " << c << " " << d << endl;
   printf("%s %s %s %s\n", a, b, c, d); 
   func(a, b, c, d);
}
