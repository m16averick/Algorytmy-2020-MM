#include <iostream>
using namespace std;

class Node {
public:
  int num;
  Node * next;
};

class intHashTable {
private:
  int size;
  Node ** table;
public:
  intHashTable(int size);  // construct a new hash table with size elements
  ~intHashTable();     // delete the memory for all internal components
  void insert(int num);    // insert num into the hash table, no effect
               // if num is already in table
  void remove(int num);    // remove num from the hash table, no effect if not in table
  int lookup(int num);     // return 1 if num is already in table, 0 otherwise
  void print(void);        // print the elements of the hash table to the screen
};

// construct a new hash table with nelements elements
intHashTable::intHashTable(int nelements)
{
  size = nelements;
  table = new Node*[size];
  for ( int i = 0; i < size; i++ ) {
    table[i] = NULL;
  }
}

intHashTable::~intHashTable()
{
   for(int i=0; i<size; i++)
   {
      Node* temp = table[i];
      while(temp != NULL)
      {
         Node* next = temp->next;
         delete temp;
         temp = next;
      }
   }
   size = 0;
   delete[] table;
}

void intHashTable::insert(int num){
    int location = ((unsigned)num) % size;
    Node *runner = table[location];
    if(runner == NULL ){
    runner->num = num;
     }else{
        while(runner != NULL ){
            runner = runner->next;
        }
        runner->num = num;
    }
   }

int main(){
    intHashTable a (10);
    a.insert(2);
    return 0;
}