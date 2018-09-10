#include<iostream>
using namespace std;
 
int& fun1()
{
    static int x = 10;
    return x;
}

int* fun2()
{
    int x = 10;
    return &x;
}

int& fun3()
{
    int x = 10;
    return x;
}

int main()
{
    fun1() = 30;
    cout << fun1();
    cout << *fun2();
    cout << fun3();
    return 0;
}
