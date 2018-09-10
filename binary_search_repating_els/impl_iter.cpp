#include <iostream>

using namespace std;

/*
 left side        right side
<--------->   |   <--------->
l     mid-1  mid  mid+1     r
*/

//a iterative binary search function. It returns location of x in
//given array arr[l..r] if present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
  while (l <= r)
  {
    int mid = (l + r)/2; //l + (r-l)/2;
 
    if ((mid == 0 || x > arr[mid-1]) && (arr[mid] == x))
      return mid;  //check if x is present at mid
 
    if (x > arr[mid])
      l = mid + 1; //if x greater, ignore left half --> restrict to right side
 
    else 
      r = mid - 1; //if x is smaller, ignore right half --> restrict to left side
  }
  
  return -1; //if we reach here, then element was not present
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
