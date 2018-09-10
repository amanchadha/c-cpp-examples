#include <iostream>

using namespace std;

class Wacko 
{
private:
  string s1, s2;

public:
  Wacko(const char *s): s1(s), s2(0) 
  {
      //test
  }
  //Wacko(char *s): s1(s), s2(0) 
  //{
      //test
  //}
  Wacko(const Wacko& rhs): s1(rhs.s1), s2(0) 
  {
      //test
  }
};

int main()
{
Wacko w1("Hello world!");
//Wacko w1 = "Hello world!";
//Wacko w2 = w1;
}
