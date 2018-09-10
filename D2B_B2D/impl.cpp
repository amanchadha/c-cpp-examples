#include <iostream>

using namespace std;

class Base
{
  public:
    virtual void test()
    {
      cout << "Base::test()" << endl;
    }
    
    void non_virt_Base()
    {
      cout << "Base::non_virt_Base()" << endl;
    }
};

class Derived: public Base
{
  public:
    Derived()
    {
      cout << "Derived Constructor" << endl;
    }

    ~Derived()
    {
      cout << "Derived Destructor" << endl;
    }

    void test()
    {
      cout << "Derived::test()" << endl;
    }

    void non_virt_Derived()
    {
      cout << "Derived::non_virt_Derived()" << endl;
    }
};

class XYZ
{
  public:
  void me_xyz()
  {
    cout << "ME XYZ()" << endl;
  }
};

int main()
{
  {
    cout << "Parent<->SubClass Related Classes" << endl;
    Base* b1 = new Derived;
    Base b2;
    Base* b3 = new Base;

    //B2D
    Derived *d1 = (Derived*) b1;
    d1->non_virt_Derived();

    cout << "******" << endl;

    //Derived d2 = (Derived) b2; -- DOESNT WORK
    //d2.non_virt();
    Derived* d2 = (Derived*) &b2;
    d2->non_virt_Derived();
    ((Derived*) &b2)->non_virt_Derived();

    cout << "******" << endl;

    Derived* d3 = (Derived*) b3;
    d3->non_virt_Derived();
    ((Derived*) b3)->non_virt_Derived();

    cout << "******" << endl;

    Base* b4 = new Base;
    Derived* d4 = static_cast<Derived*>(b4); // this works
    XYZ* d8 = static_cast<XYZ*>(b4); // this works
    d4->non_virt_Derived();
    d4->non_virt_Base();
    
    cout << "******" << endl;

    //Base* b5 = new Base;
    Base* b5 = new Derived;
    Derived* d5 = dynamic_cast<Derived*>(b5); // this works
    d5->non_virt_Derived();
    d5->non_virt_Base();

    cout << "******" << endl;

    Base* b6 = new Base;//Derived;
    Derived* d6 = dynamic_cast<Derived*>(b6); // this works
    d6->non_virt_Derived();
    d6->non_virt_Base();

    cout << "******" << endl;

    Base* b7 = new Base;//Derived;
    XYZ* d7 = dynamic_cast<XYZ*>(b7); // this works
    d7->me_xyz();
    //d7->non_virt_Derived();
    //d7->non_virt_Base();
  }
    
  cout << "******" << endl;
  
  {
    //D2B -- POLYMORPH
    Derived* d4;
    Base* b4 = static_cast<Base*>(d4); // this works
    b4->non_virt_Base();
  }

  /*
  {
    cout << "Unrelated Related Classes" << endl;
    Base* b1 = new XYZ;//Derived;
    Base b2;

    //B2D
    Derived *d1 = (Derived*) b1;
    d1->non_virt_Derived();

    //Derived d2 = (Derived) b2;
    //d2.non_virt();
    Derived* d3 = (Derived*) &b2;
    d3->non_virt_Derived();
  }
  */
}
