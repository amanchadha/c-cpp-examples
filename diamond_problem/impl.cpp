#include <iostream>

using namespace std;

class X
{
        public:
          X();
          virtual void read();//=0; //this becomes pure virtual making X an abstract class
          virtual void write(); //class
          virtual ~X();
        
        private:
          int x;
};

class A: public virtual X
{
        public:
        void write()
        {
            cout << "Hey there!" << endl;
            //read();
        }
};

class B: public virtual X 
{
        //public:
          //void read();
};

class C: public A, public B
{
        //public:
          
};

int main()
{
        C *rad = new C();
        //A *r1 = rad;
        //B *r2 = rad;

        rad->write();
        //r1->write();
        //r2->write();
        return 1;
}
