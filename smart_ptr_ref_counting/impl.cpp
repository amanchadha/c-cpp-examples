#include <iostream>

using namespace std;

#if 0
template <class T>
class SP
{
   T *ptr;  // Actual pointer
public:
   // Constructor
   explicit SP(T *p = NULL) { ptr = p; }
 
   // Destructor
   ~SP() { delete(ptr); }

    void disp()
    {
      cout << "I'm here!" << endl;
    }
 
   // Overloading dereferncing operator
   T & operator * () {  return *ptr; }
 
   // Overloding arrow operator so that members of T can be accessed
   // like a pointer (useful if T represents a class or struct or 
   // union type)
   T * operator -> () { return ptr; }
};
//#endif

class RC
{
    private:
    int count; // Reference count

    public:
    void AddRef()
    {
        // Increment the reference count
        count++;
    }

    int Release()
    {
        // Decrement the reference count and
        // return the reference count.
        return --count;
    }
};

template < typename T > class SP
{
private:
    T*    pData;       // pointer
    RC* reference; // Reference count

public:
    SP() : pData(0), reference(0) 
    {
        // Create a new reference 
        reference = new RC();
        // Increment the reference count
        reference->AddRef();
    }

    void disp()
    {
      cout << "I'm here!" << endl;
    }

    SP(T* pValue) : pData(pValue), reference(0)
    {
        // Create a new reference 
        reference = new RC();
        // Increment the reference count
        reference->AddRef();
    }

    SP(const SP<T>& sp) : pData(sp.pData), reference(sp.reference)
    {
        // Copy constructor
        // Copy the data and reference pointer
        // and increment the reference count
        reference->AddRef();
    }

    ~SP()
    {
        // Destructor
        // Decrement the reference count
        // if reference become zero delete the data
        if(reference->Release() == 0)
        {
            cout << "Deleting data..." << endl;
            delete pData;
            delete reference;
        }
    }

    T& operator* ()
    {
        return *pData;
    }

    T* operator-> ()
    {
        return pData;
    }
    
    SP<T>& operator = (const SP<T>& sp)
    {
        // Assignment operator
        if (this != &sp) // Avoid self assignment
        {
            // Decrement the old reference count
            // if reference become zero delete the old data
            if(reference->Release() == 0)
            {
                delete pData;
                delete reference;
            }

            // Copy the data and reference pointer
            // and increment the reference count
            pData = sp.pData;
            reference = sp.reference;
            reference->AddRef();
        }
        return *this;
    }
};
#endif
//#if 0
template < typename T > class SP
{
private:
    T*    pData;       // pointer
    //RC* reference; // Reference count
    int count;

public:
    SP() : pData(0)//, reference(0) 
    {
        // Create a new reference 
        //reference = new RC();
        // Increment the reference count
        //reference->AddRef();
        count = 0;
        count++;
    }

    void disp()
    {
      cout << "I'm here!" << endl;
    }

    SP(T* pValue) : pData(pValue)//, reference(0)
    {
        count = 0;
        // Create a new reference 
        //reference = new RC();
        // Increment the reference count
        //reference->AddRef();
        count++;
    }

    SP(const SP<T>& sp) : pData(sp.pData)//, reference(sp.reference)
    {
        count = sp.count;
        // Copy constructor
        // Copy the data and reference pointer
        // and increment the reference count
        //reference->AddRef();
        count++;
    }

    ~SP()
    {
        // Destructor
        // Decrement the reference count
        // if reference become zero delete the data
        if(--count == 0)
        {
            cout << "Deleting data..." << endl;
            delete pData;
            //delete reference;
        }
    }

    T& operator* ()
    {
        return *pData;
    }

    T* operator-> ()
    {
        return pData;
    }
    
    SP<T>& operator = (const SP<T>& sp)
    {
        // Assignment operator
        if (this != &sp) // Avoid self assignment
        {
            // Decrement the old reference count
            // if reference become zero delete the old data
            //if(reference->Release() == 0)
            if(count == 0)
            {
                delete pData;
                //delete reference;
            }

            // Copy the data and reference pointer
            // and increment the reference count
            pData = sp.pData;
            //reference = sp.reference;
            count = sp.count;
            //reference->AddRef();
            count++;
        }
        return *this;
    }
};
//#endif

int main()
{
  SP<int> s(new int);
  {
    //SP<int> p = s;
  }
  s.disp();

    SP<int> p(new int(10));
    p.disp();
    {
        SP<int> q = p;
        q.disp();
        // Destructor of q will be called here..

        SP<int> r;
        r = p;
        r.disp();
        // Destructor of r will be called here..
    }
    p.disp();
    // Destructor of p will be called here 
    // and person pointer will be deleted
}
