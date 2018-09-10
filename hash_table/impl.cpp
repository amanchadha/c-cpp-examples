#include <iostream>

using namespace std;

class HashEntry {
private:
      int key;
      int value;
public:
      HashEntry(int key, int value) {
            this->key = key;
            this->value = value;
      }
 
      int getKey() {
            return key;
      }
 
      int getValue() {
            return value;
      }
};
 
const int TABLE_SIZE = 128;
 
class HashMap {
private:
      HashEntry **table;
public:
      HashMap() {
            table = new HashEntry*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                  table[i] = NULL;
      }
 
      int get(int key) {
            int hash = (key % TABLE_SIZE);
            while (table[hash] && table[hash]->getKey() != key) //find the key
                  hash = (hash + 1) % TABLE_SIZE;
            if (!table[hash]) //key NOT present - return -1
                  return -1;
            else
                  return table[hash]->getValue();
      }
 
      void put(int key, int value) {
            int hash = (key % TABLE_SIZE);
            while (table[hash] && table[hash]->getKey() != key) //open addressing
                  hash = (hash + 1) % TABLE_SIZE;
            if (table[hash]) //key present - so update the value
                  delete table[hash];
            table[hash] = new HashEntry(key, value);
      }     
 
      ~HashMap() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i])
                        delete table[i];
            delete[] table;
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
