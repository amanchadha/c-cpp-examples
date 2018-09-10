#include <stdio.h> //printf
#include <stdlib.h> //malloc 

class LinkedList
{
  private: //class attrs are private by default
  struct node
  {
    int data;
    struct node* next; //left, *right;
    struct node* prev;
  } *head;
  
  public:
  LinkedList()
  {
    head = NULL;
  }

  struct node* newNode(int data)
  {
    struct node* newNode = (struct node*) malloc(sizeof(struct node)); //new struct node;
    newNode->data = data;
    newNode->next = NULL;
    #ifdef DLL
      newNode->prev = NULL;
    #endif
  
    return newNode;
  }
  
  //push node at the first available slot
  void pushNode(int data)
  {
    struct node* current = head, *temp;
  
    //treat head as a special case for both SLL and DLL
    if (!head)
    {
      temp = newNode(data);
      temp->next = NULL;
      temp->prev = NULL;
      head = temp;
    }
    //treat insertion at end as a special case for DLL
    else
    {
      //reach the end
      while (current->next)
        current = current->next;
      
      //setup temp
      temp = newNode(data);
      temp->next = NULL;
      #ifdef DLL
        temp->prev = current;
        //temp->next->prev = temp; //cant do that since temp->next is NULL
      #endif
      
      //add in temp
      current->next = temp;
    }
  }
  
  int getLength()
  {
    struct node* current = head;
    int length = 0;
  
    while (current)
    {
      length++;
      current = current->next;  
    }
  
    //printf("[getLength] Current length of LL determined as: %d\n", length);  
  
    return length;
  }
  
  //delete node at beginning (deleteBeg) or delete node at specific (deleteSpecific) or delete node at end (deleteEnd)
  void deleteNode(int pos)
  {
    struct node* current = head, *backup;
    int length = 0, iter = 1, data = 0;
  
    if (pos != 0)
    {
      //deteremine length of LL 
      length = getLength();
  
      //get the pointer to the previous node, i.e., the node before the point of deletion
      while (current->next && iter < (pos-1))
      {
        current = current->next;
        iter++;
      }
  
      #if 0
      //can also use the below code block to det length of LL but this does NOT yield the previous node 
      //as a byproduct for insertion/deletion operations unlike the above method
      length = 0;
      while (current && length < pos)
      {
        length++;
        current = current->next;  
      }
      #endif    
    }
  
    //deleteBeg: treat deletion at head as a special case for both SLL and DLL
    if (!pos) //if (pos == 0)
    {
      backup = head;
      head = head->next; //gulping action
      data = head->data;
      free(backup);
      #ifdef DLL
        head->prev = NULL;
        //head->prev->next = head; //cant do that since head->prev is NULL
        head->next->prev = head;
      #endif
  
      printf("[deleteNode] Node deleted at the beginning of LL with data %d\n", data);
    }
    //deleteEnd: treat deletion at end as a special case for DLL
    else if (pos == length)
    {
      //assuming current points to the previous node before NULL, i.e., the last node
      backup = current->next;
      current->next = current->next->next; //or can be set as NULL; //gulping action
      data = backup->data;
      free(backup);
      #ifdef DLL
        //current->next->prev = current; //cant do that since current->next is NULL
      #endif    
      
      printf("[deleteNode] Node deleted at end of LL with data %d\n", data);
    }
    //deleteSpecific: no special for deletion at anywhere between start/head and end for either SLL and DLL
    else if (pos < length)
    {
      //assuming current points to the previous node before NULL, i.e., the last node
      backup = current->next;
      current->next = current->next->next; //gulping action
      data = backup->data;
      free(backup);
      #ifdef DLL
        current->next->prev = current; 
      #endif    
      
      printf("[deleteNode] Node deleted at position %d of LL with data %d\n", pos, data);
    }
    else
      printf("[deleteNode] Invalid position");  
  }
  
  //add node at beginning (addBeg) or add node at specific (addSpecific) or add node at end (addEnd)
  void addNode(int pos, int data)
  {
    struct node* current = head, *temp;
    int length = 0, iter = 1;
  
    if (pos != 0)
    {
      //determine length of LL 
      length = getLength();
  
      //get the pointer to the previous node, i.e., the node before the point of insertion
      while (current->next && iter < (pos-1))
      {
        current = current->next;
        iter++;
      }
  
      #if 0
      //can also use the below code block to det length of LL but this does NOT yield the previous node 
      //as a byproduct for insertion/deletion operations unlike the above method
      length = 0;
      while (current && length < pos)
      {
        length++;
        current = current->next;  
      }
      #endif    
    }
  
    //addBeg: treat insertion at head as a special case for both SLL and DLL
    if (!pos) //if (pos == 0)
    {
      //assuming current points to the head node 
      
      //setup temp
      temp = newNode(data);
      temp->next = head;
      #ifdef DLL
        temp->prev = NULL;
        temp->next->prev = temp;
      #endif
  
      //update head
      head = temp;
    
      printf("[addNode] Node with value %d inserted at the beginning of LL\n", data);
    }
    //addEnd: treat insertion at end as a special case for DLL
    else if (pos == length+1)
    {
      //assuming current points to the previous node before NULL, i.e., the last node
      
      //setup temp
      temp = newNode(data);
      temp->next = NULL;
      #ifdef DLL
        temp->prev = current;
        //temp->next->prev = temp; //cant do that since temp->next is NULL
      #endif    
      
      //add in temp
      current->next = temp;
      
      printf("[addNode] Node with value %d inserted at the end of LL\n", data);
    }
    //addSpecific: no special for insertion at anywhere between start/head and end for either SLL and DLL
    else if (pos <= length)
    {
      //need to setup the node first in a temp variable to avoid overwriting the next ptr of the previous node
      //this is not neccessary for addBeg or addEnd
      
      //setup temp
      temp = newNode(data);
      temp->next = current->next;
      #ifdef DLL
        temp->prev = current;
        temp->next->prev = temp;
      #endif
      
      //add in temp
      current->next = temp;
      
      printf("[addNode] Node with value %d inserted at position %d of LL\n", data, pos);
    }
    else
      printf("[addNode] Invalid position");
  }
  
  void popNode()
  {
    struct node* backup;
    int data;
  
    //does LL have something to pop?
    if (head)
    {
      //extract data
      data = head->data; 
  
      //backup the head node
      backup = head;
      head = head->next;
      #ifdef DLL
        head->prev = NULL;
      #endif
      free(backup);
    
      printf("[popNode] Popped element with data: %d\n", data);
    }
    else
      printf("[popNode] Nothing to pop!\n");
  }
  
  void deleteLL()
  {
    struct node* current = head, *backup;
    
    printf("[deleteLL] Deleting linked list...\n");
  
    while (current)
    {
      backup = current;
      current = current->next;
      free(backup);
    }
  
    head = NULL;
  }
  
  void printLL()
  {
    struct node* current = head;
    
    //if there is a LL, i.e., head isn't NULL
    if (current)
    {
      printf("[printLL] Printing linked list...\n\t");
  
      while(current)
      {
        printf("%d ", current->data);
        current = current->next;
      }
  
      printf("\n");
    }
    else
      printf("[printLL] Nothing to print!\n");
  
  }
  
  void reverseLL()
  {
    struct node* current = head, *backup, *result = NULL;
  
    while(current)
    {
      backup = current->next; //for loop traversal
      current->next = result; //actual line doing reversal
      result = current; //update result to point to the beginning of the reverse list thus far populated
      current = backup; //get traversing...
    }
  
    head = result;
  }
  
  void printDLL()
  {
    //print LL in a reverse manner using prev ptrs -- only works for DLL
    struct node* current = head;
  
    //if there is a LL, i.e., head isn't NULL
    if (current)
    {
      //get to the last node
      while(current->next)
        current = current->next;
      printf("[printDLL] Printing linked list using prev ptrs...\n\t");
  
      while(current)
      {
        printf("%d ", current->data);
        current = current->prev;
      }
  
      printf("\n");
    }
    else
      printf("[printDLL] Nothing to print!\n");
  
  }
};

int main()
{
  LinkedList ll;
  
  //1 -> 2 -> 3 -> 4 -> 5
  ll.pushNode(1);
  ll.pushNode(2);
  ll.pushNode(3);
  ll.pushNode(4);
  ll.pushNode(5);
  
  //print LL
  ll.printLL();
  
  #ifdef DLL
    //print DLL
    ll.printDLL();
  #endif

  //popNode 1
  ll.popNode();

  //popNode 2
  ll.popNode();
  
  //print LL
  ll.printLL();

  #ifdef DLL
    //print DLL
    ll.printDLL();
  #endif  

  //get length
  ll.getLength();
  
  //add node at pos 2
  ll.addNode(2, 10);

  //print LL
  ll.printLL();  

  //add node at pos 4, the end of LL
  ll.addNode(4, 100);

  //print LL
  ll.printLL();

  #ifdef DLL
    //print DLL
    ll.printDLL();
  #endif  

  //remove node at the end of LL
  ll.deleteNode(4);

  //print LL
  ll.printLL();

  #ifdef DLL
    //print DLL
    ll.printDLL();
  #endif  
  
  ll.reverseLL();
  
  //print LL
  ll.printLL();

  //cleanUp
  ll.deleteLL();

  //print LL -- confirm deletion
  ll.printLL();

  #ifdef DLL
    //print DLL
    ll.printDLL();
  #endif  
}
