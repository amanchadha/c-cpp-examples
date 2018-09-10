#include<iostream>
 
int main()
{
  int x = 10;
  x++; ++x;
  std::cout << x; //12
  
  //difference is here
  x = 10;
  std::cout << x++; //10
  
  x = 10;
  std::cout << ++x; //11
}
