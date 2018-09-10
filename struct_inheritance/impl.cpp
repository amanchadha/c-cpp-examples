#include <stdio.h>

struct BaseStruct
{
  int x;
};

struct DerivedStruct: BaseStruct
{
  private:
  int y;

  public:
  int getX()
  {
    return x;
  }
};

class BaseClass
{
  public:
    int x;
};

class DerivedClass: public BaseClass
{
  int y;
  public:
    int getX()
    {
      return x;
    }
};

int main(void)
{
  struct DerivedStruct s;
  DerivedClass c;

  printf("Accessing element within Derived Struct...\n");
  printf("%d\t%d\n", s.x, s.getX());
  
  printf("Accessing element within Derived Class...\n");
  printf("%d\t%d\n", c.x, c.getX());
}
