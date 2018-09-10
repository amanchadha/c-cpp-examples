#include <iostream>

using namespace std;

struct add_struct
{
  int x, y;
  int extra; //diff number of elems in diff structs
};

struct sub_struct
{
  int x, y;
};

int add(void* a)
{
  //return 0;
  return (((add_struct*)a)->x + ((add_struct*)a)->y);
}

int subtract(void* b)
{
  //return 1;
  return (((sub_struct*)b)->x - ((sub_struct*)b)->y);
}

//typedef int (*func)();
typedef int (*func)(void*);

func ptrs[] = {add, subtract};

int main()
{
  add_struct a;
  sub_struct b;
  a.x = 20; a.y = 10;
  b.x = 20; b.y = 10;

  char ch;
  cout << "Enter 0 or 1 to launch the corresponding fn through its pointer..." << endl;
  cin >> ch;
  cout << "You entered: " << (int) ch << endl; //48 for 0, 49 for 1

  if (ch == 48 || ch == 49) 
    //cout << ptrs[ch-48]() << endl;
    cout << ptrs[ch-48](&a) << endl;

  cout << endl << "Using a for-loop to iterate through all the fn pointers..." << endl;
  for (int i = 0 ; i < sizeof(ptrs)/sizeof(ptrs[0]); ++i)
    //cout << ptrs[i]() << endl;
    cout << ptrs[i](&a) << endl;
   
  cout << endl << "Using name-calling thru fn pointers..." << endl;
  cout << ptrs[0](&a) << endl;
  cout << ptrs[1](&b) << endl;
}
