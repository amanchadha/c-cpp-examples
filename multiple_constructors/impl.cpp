#include <iostream>

using namespace std;

class S
{
    public:
    S(int x = 0)
    {
      cout << "Constructor: " << x << endl;
    }

    int x;
};

int main()
{
 S s1;
 S s2(10);
}
