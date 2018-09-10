#include <cstdio>

using namespace std;

int main()
{
  int x[10];

  scanf("%d", x);

  printf("%d", x[0]);
  
  scanf("%d", &x);

  printf("%d", x[0]);
  
  scanf("%d", &x[0]);

  printf("%d", x[0]);
}
