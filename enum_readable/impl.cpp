#include <iostream>
#include "enumdef.h"

using namespace std;

//moving to a header
/*
typedef enum _dont_care_
{
  NUM0,
  NUM1,
  NUM2
} eReadableCode;
*/

void func(eReadableCode RC)
{
  if (RC == NUM1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

void func1(int x)
{
  if (x == NUM1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main(void)
{
  int x = NUM0;
  cout << x << endl;

  eReadableCode RC = NUM1;
  x = RC;
  cout << x << endl;

  func(NUM1);
  func1(NUM1);
}
