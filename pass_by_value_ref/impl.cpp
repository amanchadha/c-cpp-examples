#include <iostream>

using namespace std;

class Base
{
  public:
  Base()
  {
    cout << "CTor" << endl;
  }
  
  ~Base()
  {
    cout << "DTor" << endl;
  }

  Base(const Base& rhs)
  {
    cout << "Copy CTor" << endl;
  }

  Base& operator=(const Base& rhs)
  {
    cout << "Assignment Op" << endl;
  }
};

void pass_by_val(Base b)
{
  cout << "Pass by value..." << endl;
}

void pass_by_ref(const Base& b)
{
  cout << "Pass by ref..." << endl;
}

int main(void)
{
  Base b1, b2 = b1;

  cout << "***************" << "Begin pass by value" << "***************" << endl;
  pass_by_val(b1);
  cout << "***************" << "End pass by value" << "***************" << endl;
  
  cout << "***************" << "Begin pass by ref" << "***************" << endl;
  pass_by_ref(b2);
  cout << "***************" << "End pass by ref" << "***************" << endl;
}
