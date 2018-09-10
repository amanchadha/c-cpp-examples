#include <iostream>

using namespace std;

int binarySearchR(int arr[], int low, int high, int x)
{
    if (high >= low)
    {
        int mid = (low + high)/2; /*low + (high - low)/2;*/
 
        /* Check if arr[mid] is the first occurrence of x.
            arr[mid] is first occurrence if x is one of the following
            is true:
            (i) mid == 0 and arr[mid] == x
            (ii) arr[mid-1] < x and arr[mid] == x
        */
        if ( (mid == 0 || x > arr[mid-1]) && (arr[mid] == x) )
            return mid;
        else if (x > arr[mid])
            return binarySearchR(arr, (mid + 1), high, x);
        else
            return binarySearchR(arr, low, (mid - 1), x);
    }
 
    return -1;
}

int binarySearchI(int arr[], int low, int high, int x)
{
    while (high >= low)
    {
        int mid = (low + high)/2; /*low + (high - low)/2;*/
 
        /* Check if arr[mid] is the first occurrence of x.
            arr[mid] is first occurrence if x is one of the following
            is true:
            (i) mid == 0 and arr[mid] == x
            (ii) arr[mid-1] < x and arr[mid] == x
        */
        if ( (mid == 0 || x > arr[mid-1]) && (arr[mid] == x) )
            return mid;
        else if (x > arr[mid])
            low = mid + 1;
        else
            high = mid + 1;
    }
 
    return -1;
}
 
/* Driver program to check above functions */
int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    cout << binarySearchR(arr, 0, n-1, x) << endl;
    cout << binarySearchI(arr, 0, n-1, x) << endl;
    
    x = 10;
    cout << binarySearchR(arr, 0, n-1, x) << endl;
    cout << binarySearchI(arr, 0, n-1, x) << endl;
    
    return 0;
}
