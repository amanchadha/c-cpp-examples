#include <iostream>

using namespace std;

class String {
  public:
    /*explicit*/ String (int n) //allocate n bytes
    {
      cout << "String::int";
    }
    String(const char *p); // initialize sobject with string p
    /*String(const char p) // initialize sobject with string p
    {
      cout << "String::char" ;
    }*/
};

int main()
{
  String x = 'a';
}
