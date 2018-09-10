#include <iostream>
#include <ctime>

using namespace std;

enum 
{
  C0 = 0,
  C1 = 1,
  C2 = 2
};

int arr[] = {C0, C1, C1, C1, C1, C2};

int main(int argc, char** argv)
{
  srand(time(NULL));

  for (int i = 0; i < 100; ++i)
    cout << arr[rand() % 7] << endl;
}
