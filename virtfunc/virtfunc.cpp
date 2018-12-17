//mixing virtual functions and overriden functions

#include<iostream>

using namespace std;

class Base
{
public:
    //virtual double Function(int i) const{std::cout<<"\nIn Base int version "<< i;}
    //virtual double Function(double i) const{std::cout<<"\nIn Base double version "<< i;}
    virtual double Function(char i) const{std::cout<<"\nIn Base char version "<< i;}
    void Function1() { std::cout << "\nIn the Base Function1 version..."; }
};

class SubClass : public Base
{
public:
    double Function(int i) const{std::cout<<"\nIn Derived int version";}
    double Function(std::string str) const{std::cout<<"\nIn Derived string version";}
    double Function(double i) const {std::cout<<"\nIn Derived double version";}
    void Function1() { std::cout << "\nIn the Dervied Function1 version..."; }
};

int main()
{
    SubClass obj;
    obj.Function(10);
    obj.Function(10.1);
    obj.Function("Hello"); 

    cout << "\n*********\n";
    Base Bobj;
    Bobj.Function(10.2);
    Bobj.Function1();

    cout << "\n*********\n";
    Base *ptr = new Base;
    ptr->Function(10.5);
    ptr->Function1();

    cout << "\n*********\n";
    Base *ptr2 = new SubClass; 
    ptr2->Function(10);
    ptr2->Function(10.5);
    ptr2->Function1();

    cout << "\n*********\n";
    SubClass *ptr3 = new SubClass; 
    ptr3->Function(10.5);
    ptr3->Function1();    

    cout << "\n*********\n";
    ptr2 = new Base(); //use () or not doesnt matter since () is empty  
    ptr2->Function1();    

    delete ptr;
    delete ptr2;
    delete ptr3;
    //leak for the memory pointed by ptr2 earlier (new SubClass) right here -- number of new's should match number of delete's
    return 0;
}

#if 0 
//(with virtual function which accepts an int in the base)
o/p:
In Derived int version
In Derived double version
In Derived string version
*********

In Base int version 10
In the Base Function1 version...
*********

In Base int version 10
In the Base Function1 version...
*********

In Derived int version <--- ***
In Derived int version <--- ***
In the Base Function1 version...
*********

In Derived double version
In the Dervied Function1 version...
*********

In the Base Function1 version...
#endif

#if 0 
//(with virtual function which accepts a double in the base)
o/p:
In Derived int version
In Derived double version
In Derived string version
*********

In Base double version 10.2
In the Base Function1 version...
*********

In Base double version 10.5
In the Base Function1 version...
*********

In Derived double version <--- ***
In Derived double version <--- ***
In the Base Function1 version...
*********

In Derived double version
In the Dervied Function1 version...
*********

In the Base Function1 version...
#endif

#if 0 
//(with virtual function which accepts a char in the base)
In Derived int version
In Derived double version
In Derived string version
*********

In Base char version 

In the Base Function1 version...
*********

In Base char version 

In the Base Function1 version...
*********

In Base char version <--- ***

In Base char version <--- ***

In the Base Function1 version...
*********

In Derived double version
In the Dervied Function1 version...
*********

In the Base Function1 version...
#endif
