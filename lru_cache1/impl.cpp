#include <iostream>

using namespace std;

typedef struct {
    int key;
    int val;
} elem;
 
class LRUCache{
public:
    elem *arr; 
    int size;  // total number of elements in the list currently
    int capacity;
 
    LRUCache(int capacity) {
        arr = new elem[capacity];
        size = 0;
        this->capacity = capacity;
    }
 
    /* move the used element to the end of list */
    void adjust(int a) {
        if (a == size - 1) {
            return ;
        }
        elem cur = arr[a]; 
        for (int i = a; i < size - 1; i ++) {
            arr[i] = arr[i + 1]; // move others 1 pos left
        }
        arr[size - 1] = cur; // move to the end
    }
 
    int get(int key) {
        for (int i = 0; i < size; i ++) {
            if (arr[i].key == key) {
                int a = arr[i].val;
                adjust(i);
                return a; // existent key
            }
        }
        return -1;
    }
 
    void set(int key, int value) {
        for (int i = 0; i < size; i ++) {
            if (arr[i].key == key) { // existent
                arr[i].val = value;
                adjust(i);
                return;
            }
        }
        if (size == capacity) { // check if reach the capacity
            for (int i = 0; i < size - 1; i ++) {
                arr[i] = arr[i + 1]; // delete the least used element
            }
            arr[size - 1].key = key;
            arr[size - 1].val = value;
        } else {
            arr[size].key = key;
            arr[size].val = value;            
            size++; // increase the size
        }
    }
};

int main()
{
  LRUCache cache(4);

  cache.set(1, 1);
  cache.set(2, 2);
  cache.set(3, 3);
  cache.set(1, 1);
  cache.set(4, 4);
  cache.set(5, 5);
  
  cout << cache.get(1) << endl;
  cout << cache.get(2) << endl;
  cout << cache.get(3) << endl;
  cout << cache.get(1) << endl;
  cout << cache.get(4) << endl;
  cout << cache.get(5) << endl;
  
  for (int i = 0; i < cache.size; ++i)
    cout << cache.arr[i].key << endl; //3145
}
