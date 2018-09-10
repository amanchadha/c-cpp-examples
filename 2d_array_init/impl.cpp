#include <iostream>

using namespace std;

int main()
{
  int **arr; //2D int array
  arr = (int**) calloc(2, sizeof(int*)); 

  for(int i = 0; i < 2; i++)
    if(!(arr[i] = (int*) calloc(2, sizeof(int))))
    {
      cout << "Memory cannot be allocated";
      return 1;
    }
     
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      cout << arr[i][j] << endl;
}
