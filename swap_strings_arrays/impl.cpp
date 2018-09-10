#include <iostream>
#include <string.h>

using namespace std;

//not a proper way to swap strings by swapping pointer values
void swap(char *str1, char *str2)
{
  char* temp = str1;
  str1 = str2;
  str2 = temp;
}

//swaps strings by swapping pointers
//If you are using character pointer for strings (not arrays) then change str1 and str2 to point each other’s data. i.e., swap pointers. 
//In a function, if we want to change a pointer (and obviously we want changes to be reflected outside the function) then we need to pass a pointer to the pointer.
void swap1(char **str1_ptr, char **str2_ptr)
{
  char* temp = *str1_ptr;
  *str1_ptr = *str2_ptr;
  *str2_ptr = temp;
}  

//swaps strings by swapping data
void swap2(char *str1, char *str2)
{
  char* temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
  free(temp);
}  

//proper way to swap chars -- by reference variables
void swap3(char *&str1, char *&str2)
{
  char temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}

//proper way to swap chars -- by swapping data pointed by the pointers
void swap4(char *str1, char *str2)
{
  char temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}

//proper way to swap C++ strings -- by swapping pointer data
void swap5(string *str1_ptr, string *str2_ptr)
{
  string temp = *str1_ptr;
  *str1_ptr = *str2_ptr;
  *str2_ptr = temp;
}

//ARRAYS

//not a proper way to swap arrays -- by swapping pointer values passed onto a fn
void swap_arr(int *arr1, int *arr2)
{
  int* temp = arr1;
  arr1 = arr2;
  arr2 = temp;
}

//swaps arrays by swapping pointers
//If you are using int pointers for arrays (and not arrays) then change arr1 and arr2 to point each other’s data. i.e., swap pointers.
//In a function, if we want to change a pointer (and obviously we want changes to be reflected outside the function) then we need to pass a pointer to the pointer.
void swap_arr1(int **arr1_ptr, int **arr2_ptr)
{
  int* temp = *arr1_ptr;
  *arr1_ptr = *arr2_ptr;
  *arr2_ptr = temp;
}  

//swaps arrays by swapping data
void swap_arr2(int* arr1, int* arr2)
{
  int* temp = (int *)malloc(sizeof(int)*3);
  memmove(temp, arr1, sizeof(int)*3);
  memmove(arr1, arr2, sizeof(int)*3);
  memmove(arr2, temp, sizeof(int)*3);
  free(temp);
}  

//proper way to swap ints -- by reference variables
void swap_arr3(int*& arr1, int*& arr2)
{
  int temp = *arr1;
  *arr1 = *arr2;
  *arr2 = temp;
}

//proper way to swap ints -- by doing a pointer data swap
void swap_arr4(int *arr1, int *arr2)
{
  int temp = *arr1;
  *arr1 = *arr2;
  *arr2 = temp;
}

int main()
{
  char *str1 = "geeks";
  char *str2 = "forgeeks";
  char *temp;
  char str3[10] = "geeks";
  char str4[10] = "forgeeks";  
  string str5("geeks");
  string str6("forgeeks");
  
  int *arr1 = new int[3];
  int *arr2 = new int[3];
  int *temp_arr;
  int arr3[] = {1,2,3};
  int arr4[] = {4,5,6};
  int temp_arr1[];

  int i;

  memset(arr1, 0, sizeof(int)*3);
  memset(arr2, 0, sizeof(int)*3);
 
  for (i = 0; i < 3; i++)
    arr1[i] = i;
  
  for (i = 0; i < 3; i++)
    arr2[i] = (i+1);

  cout << "*********************\nSWAPPING STRINGS\n*********************" << endl;
  cout << "Original Strings:" << endl;
  cout << str1 << "\t" << str2 << endl;

  cout << "\n*********************\nSwapping strings by swapping pointer values -- doesnt work\n*********************\n" << endl;
  swap(str1, str2);
  cout << "str1 is " << str1 << "; str2 is " << str2 << endl;
  //printf("str1 is %s, str2 is %s", str1, str2);
  
  cout << "\n*********************\nSwapping strings by swapping pointers #1 -- can be applied if strings are stored using char pointers\n*********************\n" << endl;
  swap1(&str1, &str2);
  cout << "str1 is " << str1 << "; str2 is " << str2 << endl;
  //printf("\nstr1 is %s, str2 is %s", str1, str2);
  
  swap1(&str1, &str2); //re-swap back
  cout << "\n*********************\nSwapping strings by swapping pointers #2 inline -- can be applied if strings are stored using char pointers\n*********************\n" << endl;
  temp = str1;
  str1 = str2;
  str2 = temp;
  cout << "str1 is " << str1 << "; str2 is " << str2 << endl;
  //printf("\nstr1 is %s, str1 is %s", str2, str2);
  swap1(&str1, &str2); //re-swap back
  
  cout << "\n*********************\nSwapping strings by swapping data -- can be applied if strings are stored using char arrays\n*********************\n" << endl;
  swap2(str3, str4);
  cout << "str3 is " << str3 << "; str4 is " << str4 << endl;
  //printf("\nstr3 is %s, str4 is %s", str3, str4);
  swap2(str3, str4); //re-swap back
  
  cout << "\n*********************\nSwapping chars by swapping ref vars -- can be applied if chars are stored using char pointers\n*********************\n" << endl;
  char c1 = 'a';
  char c2 = 'b';
  char* c3 = &c1;
  char* c4 = &c2;
  //swap3(c3, c4);
  cout << "c1 is " << c1 << "; c2 is " << c2 << endl;
  //printf("\nstr3 is %s, str4 is %s", str3, str4);
  //swap3(c3, c4);
  
  // cant apply ref vars to arrays - can only do them on pointers
  
  cout << "\n*********************\nSwapping chars by swapping pointer data -- can be applied if chars are stored using char pointers\n*********************\n" << endl;
  swap4(&c1, &c2);
  cout << "c1 is " << c1 << "; c2 is " << c2 << endl;
  //printf("\nstr1 is %s, str2 is %s", str1, str2);
  
  cout << "\n*********************\nSwapping C++ strings by swapping pointers -- can be applied if strings are stored using char pointers\n*********************\n" << endl;
  swap5(&str5, &str6);
  cout << "str5 is " << str5 << "; str6 is " << str6 << endl;

  cout << "\n*********************\nSWAPPING ARRAYS\n*********************" << endl;

  cout << "Original Arrays:" << endl;
  for (i = 0; i < 3; i++)
   cout << arr1[i] << "\t" << arr2[i] << endl;

  cout << "\n*********************\nSwapping arrays by swapping pointer values -- doesnt work\n*********************\n" << endl;
  swap_arr(arr1, arr2);
  cout << "arr1 is " << arr1[0]<< "; arr2 is " << arr2[0] << endl;
  //printf("str1 is %s, str2 is %s", str1, str2);

  cout << "\n*********************\nSwapping arrays by swapping pointers #1 -- can be applied if arrays are stored using int pointers\n*********************\n" << endl;
  swap_arr1(&arr1, &arr2);
  cout << "arr1 is " << arr1[0]<< "; arr2 is " << arr2[0] << endl;
  //printf("\nstr3 is %s, str4 is %s", str3, str4);
  swap_arr1(&arr1, &arr2); //re-swap back
  //swap_arr1(&arr3, &arr4);

  cout << "\n*********************\nSwapping arrays by swapping pointers #2 inline -- can be applied if arrays are stored using int pointers\n*********************\n" << endl;
  temp_arr = arr1;
  arr1 = arr2;
  arr2 = temp_arr;
  cout << "arr1 is " << arr1[0]<< "; arr2 is " << arr2[0] << endl;
  //printf("\nstr3 is %s, str4 is %s", str3, str4);
  swap_arr1(&arr1, &arr2); //re-swap back
  
  cout << "\n*********************\nSwapping arrays by swapping data -- can be applied if arrays are stored using int arrays\n*********************\n" << endl;
  swap_arr2(arr3, arr4);
  cout << "arr3 is " << arr3[0] << "; arr4 is " << arr4[0] << endl;
  //printf("\nstr3 is %s, str4 is %s", str3, str4);
  swap_arr2(arr3, arr4); //re-swap back

  cout << "\n*********************\nSwapping ints by swapping ref vars -- can be applied if arrays are stored using int pointers\n*********************\n" << endl;
  swap_arr3(arr1, arr2);
  cout << "arr1 is " << arr1[0]<< "; arr2 is " << arr2[0] << endl;
  //printf("\nstr3 is %s, str4 is %s", str3, str4);
  swap_arr3(arr1, arr2); //re-swap back
  
  // cant apply ref vars to arrays - can only do them on pointers
  
  cout << "\n*********************\nSwapping ints by swapping pointer data -- can be applied if arrays are stored using int pointers\n*********************\n" << endl;
  swap_arr4(arr1, arr2);
  cout << "arr1 is " << arr1[0]<< "; arr2 is " << arr2[0] << endl;
  //printf("\nstr1 is %s, str2 is %s", str1, str2);

return 0;
}
