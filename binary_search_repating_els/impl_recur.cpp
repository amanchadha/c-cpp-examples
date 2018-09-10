#include <iostream>

using namespace std;

/*
 left side        right side
<--------->   |   <--------->
l     mid-1  mid  mid+1     r
*/

//a recursive binary search function. It returns location of x in
//given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
   if (l <= r)
   {
        int mid = (l + r)/2; //l + (r - l)/2;
 
        //if the element is present at the middle itself
        if ((mid == 0 || x > arr[mid-1]) && (arr[mid] == x))
          return mid;
 
        //if element is larger than mid, then it can only be present
        //in the right subarray
        if (x > arr[mid]) 
          return binarySearch(arr, mid+1, r, x); //restrict to right side
 
        //else the element can only be present in left subarray
        //else
        return binarySearch(arr, l, mid-1, x); //restrict to left side
   }
 
   //we reach here when element is not present in array
   return -1;
}
 
int main(void)
{
   int arr[] = {2, 3, 3, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 3;

   int result = binarySearch(arr, 0, n-1, x);

   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
   return 0;
}
