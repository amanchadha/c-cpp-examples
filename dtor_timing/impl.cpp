#include <iostream>
using namespace std;
 
int i;
 
class A
{
public:
    ~A()
    {
        i = 10;
    }
};
 
int& foo()
{
    i = 3;
    A ob;
    return i;
}
 
int main()
{
    cout << "i = " << foo() << endl;
    return 0;
}
