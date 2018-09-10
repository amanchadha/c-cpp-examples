#include <iostream>

using namespace std;

class printData 
{
   public:
      void print(int i) {
        cout << "Printing int: " << i << endl;
      }

      void print(double  f) {
        cout << "Printing float: " << f << endl;
      }

      void print(char* c) {
        cout << "Printing character: " << c << endl;
      }
};
 
void print(int i) {
  cout << "Printing int: " << i << endl;
}

void print(double  f) {
  cout << "Printing float: " << f << endl;
}

void print(char* c) {
  cout << "Printing character: " << c << endl;
}

int main(void)
{
   //no class
   //call print to print integer
   print(5);
   
   //call print to print float
   print(500.263);
   
   //call print to print character
   print("Hello C++");
 
   //with class
   printData pd;
 
   //call print to print integer
   pd.print(5);

   //call print to print float
   pd.print(500.263);

   //call print to print character
   pd.print("Hello C++");   

   return 0;
}

