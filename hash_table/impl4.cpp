#include <iostream>
#define TABLE_SIZE 128

using namespace std;
  
class HashTable {
private:
      struct record {
      	int key;
      	int value;
      } **table;

public:
      HashTable() {
            table = new record*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                  table[i] = NULL;
      }

      void setKeyValue(int hash, int key, int value)
      {
            table[hash]->key = key;
            table[hash]->value = value;
      }
 
      int getValue(int key) {
            int hash = (key % TABLE_SIZE);

            while (table[hash] && table[hash]->key != key) //find the key
                  hash = (hash + 1) % TABLE_SIZE;

            if (!table[hash]) //key NOT present - return -1
                  return -1;
            else
                  return table[hash]->value;
      }
 
      void putKeyValue(int key, int value) {
            int hash = (key % TABLE_SIZE); //since key is already a number, directly operate on it

            while (table[hash] && table[hash]->key != key) //open addressing
                  hash = (hash + 1) % TABLE_SIZE;

            if (table[hash]) //key present - so update the value
                  delete table[hash];

            table[hash] = new record;
            setKeyValue(hash, key, value);
            //table[hash]->key = key;
            //table[hash]->value = value;
      }     
 
      ~HashTable() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i])
                        delete table[i];

            delete table;
      }
};

int main()
{
  HashTable* h = new HashTable();

  h->putKeyValue(100, 10);
  cout << h->getValue(100) << endl;

  h->putKeyValue(100, 20);
  cout << h->getValue(100) << endl;

  h->putKeyValue(128, 30);
  cout << h->getValue(128) << endl;

  cout << h->getValue(1280) << endl;
}