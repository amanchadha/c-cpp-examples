#include <iostream>

using namespace std;

//--------------- iterative version ---------------------    
int fiboi(int n)
{
    int prev = 0;
    int current = 1;
    
    if (n == 0) return prev;
    if (n == 1) return current;
        
    int result = 0;
        
    for (int i = 2; i <= n; i++)
    {
        result = prev + current;
        prev = current; //a = b;
        current = result;
    }
    
    return result;
}

//--------------- naive recursive version --------------------- 
int fibor(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
        
    return fibor(n - 1) + fibor(n - 2);
}

//recursive function calculates n!
static int factr(int n)
{
    if (n <= 1) return 1;
    return n * factr(n - 1);
}

//iterative function calculates n!
static int facti(int n)
{
    int sum = 1;
    if (n <= 1) return sum;
    while (n > 1)
    {
        sum *= n;
        n--;
    }
    return sum;
}

int main()
{
 cout << facti(10) << "\t" << factr(10) << endl;
 cout << fiboi(10) << "\t" << fibor(10) << endl;
 
 //cout << facti(52787) << "\t" << factr(52787) << endl;
 //cout << fiboi(52787) << "\t" << fibor(52787) << endl;
}
