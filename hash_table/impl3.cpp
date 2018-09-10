#include <iostream>

using namespace std;
 
const int TABLE_SIZE = 128;
 
class HashMap {
private:
      struct record {
      	int key;
      	int value;
      };

      record* table;

public:
      HashMap() {
            table = new record[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                  table[i].key = NULL;
      }
 
      int get(int key) {
            int hash = (key % TABLE_SIZE);
            while (table[hash].key && table[hash].key != key)
                  hash = (hash + 1) % TABLE_SIZE;
            if (!table[hash].key)
                  return -1;
            else
                  return table[hash].value;
      }
 
      void put(int key, int value) {
            int hash = (key % TABLE_SIZE);
            while (table[hash].key && table[hash].key != key)
                  hash = (hash + 1) % TABLE_SIZE;
            table[hash].key = key;
            table[hash].value = value;
      }     
 
      ~HashMap() {
            //for (int i = 0; i < TABLE_SIZE; i++)
            //      if (table[i] != NULL)
            //            delete table[i];
            delete table;
      }
};

int main()
{
  HashMap *h = new HashMap();

  h->put(100, 10);
  cout << h->get(100) << endl;
  
  h->put(100, 20);
  cout << h->get(100) << endl;

  h->put(128, 30);
  cout << h->get(128) << endl;

  cout << h->get(1280) << endl;
}
