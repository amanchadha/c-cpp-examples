#include<iostream>

using namespace std;

int foo(int x) { 
    return x; 
}
 
char foo() {  // compiler error; new declaration of foo()
    return 'a'; 
}
 
int main()
{
    char x = foo(10);
    cout << (int) x;
    getchar();
    return 0;
}
