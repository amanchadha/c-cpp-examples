#include <iostream>
#include <string>

#define R 3
#define C 3

using namespace std;

int main()
{
  string arr1[R][C] = {{"you", "we"},
          						{"have", "are"},
					          	{"sleep", "eat", "drink"}};
  
  char* arr2[R][C] =  {{"you", "we"},
          						{"have", "are"},
					          	{"sleep", "eat", "drink"}};

  arr2[0][2] = "hey";

  cout << arr1[0][2] << " " << arr2[0][2] << endl;
}
