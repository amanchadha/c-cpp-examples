#include <stdio.h> //printf
#include <stdlib.h> //malloc 

#define true 1
#define false 0

//pointer-to-pointer args are used when the changes in a pointer (such as head node changes due to insertion of a node at the beginning of a LL) are to be reflected back in the caller
//if p is a ptr, updates to *p in a callee are reflected back in the caller, but updates to p are not reflected back in the caller.
//for functions not modifying a pointer, can simply pass a pointer (no need of a p2p).

struct node
{
  int data;
  struct node* next; //left, *right;
  #ifdef DLL
    struct node* prev;
  #endif
};

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

//push node at the first available slot, much like appendNode
void pushNode(struct node** head, int data)
{
  struct node* current = *head, *temp;

  //treat head as a special case for both SLL and DLL
  if (!*head)
  {
    temp = newNode(data);
    temp->next = NULL;
    *head = temp;
    #ifdef DLL
      temp->prev = NULL;
    #endif
    #ifdef CLL
      temp->next = temp;
    #endif
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

//get length of SLL or DLL
int getLength(struct node* head)
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

//given a pointer delete a node in SLL or DLL in O(1) time
void deleteNodePtr(struct node** head, struct node* ptr)
{
  struct node* backup;
  
  #ifndef DLL
    //instead of deleting the node at *ptr, we copy the data of the next node to the node @ *ptr and delete the next node
    ptr->data = ptr->next->data;
    backup = ptr->next;
    ptr->next = ptr->next->next;
    free(backup);
  #else
    if (*head == ptr) //head ptr to be deleted
        *head = ptr->next;
  
    if (ptr->prev) //cant do the below if the node is the *first* node
      ptr->prev->next = ptr->next;
  
    if (ptr->next) //cant do the below if the node is the *last* node
      ptr->next->prev = ptr->prev;
  
    free(ptr);
  #endif
}

//add node at beginning (addBeg) or add node at specific (addSpecific) or add node at end (addEnd)
void addNode(struct node** head, int pos, int data)
{
  struct node* current = *head, *temp;
  int length = 0, iter = 1;

  if (pos != 0)
  {
    //determine length of LL 
    length = getLength(*head);

    //get the pointer to the previous node, i.e., the node before the point of insertion
    while (current->next && iter < (pos-1))
    {
      current = current->next;
      iter++;
    }

    #if 0
    //can also use the below code block to det length of LL but this does NOT yield the previous node 
    //as a byproduct for insertion/deletion operations unlike the above method
    iter = 0;
    while (current && iter < pos)
    {
      current = current->next;
      iter++;
    }
    #endif    
  }

  //addBeg: treat insertion at head as a special case for both SLL and DLL
  if (!pos) //if (pos == 0)
  {
    //assuming current points to the head node 
    
    //setup temp
    temp = newNode(data);
    temp->next = *head;
    #ifdef DLL
      temp->prev = NULL;
      temp->next->prev = temp;
    #endif

    #ifdef CLL
      current = *head;
      //iterate to the last node
      while (current->next != *head)
        current = current->next;
    #endif

    //update head
    *head = temp;

    #ifdef CLL
      //affix the next pointer of the last node with the new start
      current->next = *head;
    #endif    
  
    printf("[addNode] Node with value %d inserted at the beginning of LL\n", data);
  }
  //addEnd: treat insertion at end as a special case for DLL
  else if (pos == length+1)
  {
    //assuming current points to the previous node before NULL, i.e., the last node
    
    //setup temp
    temp = newNode(data);
    temp->next = NULL; //OR current->next;
    #ifdef DLL
      temp->prev = current;
      //temp->next->prev = temp; //cant do that since temp->next is NULL
    #endif    
    
    //add in temp
    current->next = temp;
    
    printf("[addNode] Node with value %d inserted at the end of LL\n", data);
  }
  //addSpecific: no special case for insertion anywhere between start/head and end for either SLL and DLL
  else if (pos <= length)
  {
    //assuming current points to the previous node before the point of insertion

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

//delete node at beginning (deleteBeg) or delete node at specific (deleteSpecific) or delete node at end (deleteEnd)
void deleteNode(struct node** head, int pos)
{
  struct node* current = *head, *backup;
  int length = 0, iter = 1, data = 0;

  if (pos != 0)
  {
    //determine length of LL 
    length = getLength(*head);

    //get the pointer to the previous node, i.e., the node before the point of deletion
    while (current->next && iter < (pos-1))
    {
      current = current->next;
      iter++;
    }

    #if 0
    //can also use the below code block to det length of LL but this does NOT yield the previous node 
    //as a byproduct for insertion/deletion operations unlike the above method
    iter = 0;
    while (current && iter < pos)
    {
      current = current->next;  
      iter++;
    }
    #endif    
  }

  //deleteBeg: treat deletion at head as a special case for both SLL and DLL
  if (!pos) //if (pos == 0)
  {
    backup = *head;

    #ifdef CLL
      current = *head;
      //iterate to the last node
      while (current->next != *head)
        current = current->next;
    #endif

    *head = (*head)->next; //gulping action
    data = backup->data; //for printf purposes only

    free(backup);

    #ifdef DLL
      (*head)->prev = NULL;
      //(*head)->prev->next = *head; //cant do that since head->prev is NULL
      //(*head)->next->prev = *head; //no need of doing that since this is already in place
    #endif

    #ifdef CLL
      //affix the next pointer of the last node with the new start
      current->next = *head;
    #endif

    printf("[deleteNode] Node deleted at the beginning of LL with data %d\n", data);
  }
  //deleteEnd: treat deletion at end as a special case for DLL (but not for SLL, i.e., deletion in SLL for the last node and any middle node is the same)
  else if (pos == length)
  {
    //assuming current points to the previous node before NULL, i.e., the last node
    backup = current->next;

    current->next = current->next->next; //or can be set as NULL; //gulping action
    data = backup->data;

    free(backup);

    #ifdef DLL
      //current->prev->next = *head; //no need to do that since this is already set
      //current->next->prev = current; //cant do that since current->next is NULL
    #endif    
    
    printf("[deleteNode] Node deleted at end of LL with data %d\n", data);
  }
  //deleteSpecific: no special case for deletion anywhere between start/head and end for either SLL and DLL
  else if (pos < length)
  {
    //assuming current points to the previous node 
    backup = current->next;

    current->next = current->next->next; //gulping action
    data = backup->data;

    free(backup);

    #ifdef DLL
      //current->prev->next = *head; //no need to do that since this is already set      
      current->next->prev = current; 
    #endif    
    
    printf("[deleteNode] Node deleted at position %d of LL with data %d\n", pos, data);
  }
  else
    printf("[deleteNode] Invalid position");  
}

//extract data and remove node
int popNode(struct node** head)
{
  struct node* backup;
  int data;

  //does LL have something to pop?
  if (*head)
  {
    data = (*head)->data; //extract data

    backup = *head; //backup the head node

    *head = (*head)->next;
    #ifdef DLL
      (*head)->prev = NULL;
    #endif
    free(backup);

    return data;
  }
  else
    return -1;
}

void deleteLL(struct node** head)
{
  struct node* current = *head, *backup;
  
  printf("[deleteLL] Deleting linked list...\n");

  while (current)
  {
    backup = current;
    current = current->next;
    free(backup);
  }

  *head = NULL;
}

void printLL(struct node* head)
{
  struct node* current = head;
  
  //if there is a LL, i.e., head isn't NULL
  if (current)
  {
    printf("[printLL] Printing linked list...\n\t");

    while (current)
    {
      printf("%d ", current->data);
      current = current->next;
    }

    printf("\n");
  }
  else
    printf("[printLL] Nothing to print!\n");
}

#ifdef DLL
void printDLL(struct node* head)
{
  //print LL in a reverse manner using prev ptrs -- only works for DLL
  struct node* current = head;

  //if there is a LL, i.e., head isn't NULL
  if (current)
  {
    //get to the last node
    while (current->next)
      current = current->next;
    printf("[printDLL] Printing linked list using prev ptrs...\n\t");

    while (current)
    {
      printf("%d ", current->data);
      current = current->prev;
    }

    printf("\n");
  }
  else
    printf("[printDLL] Nothing to print!\n");
}
#endif

void printKthFromEndLL(struct node* head, int k)
{
  static int count = 0; //value needs to be maintained across function calls

  //if there is a LL, i.e., head isn't NULL
  if (head)
  {
    printKthFromEndLL(head->next, k);
  
    //count++; //same as using ++count *directly* below

    //base case
    if (++count == k)
    {
      printf("%d", head->data);
      printf("\n");
      return;
    }
  }
}

void reverseLL(struct node** head)
{
  struct node* current = *head, *backup, *result = NULL;

  while (current)
  {
    backup = current->next; //for loop traversal
    current->next = result; //actual line doing reversal
    #ifdef DLL
      if (current->next)
        current->next->prev = current;
    #endif
    result = current; //update result to point to the beginning of the reverse list thus far populated
    current = backup; //get traversing...
  }

  *head = result;
}

#if 0
//below code counts the elements from the head and not the end

void printKthFromEndLL(struct node* head, int k)
{
  static int count = 1; //value needs to be maintained across function calls

  //if there is a LL, i.e., head isn't NULL
  if (head && head->next)
  {
    //base case
    if (count == k)
    {
      printf("%d", head->data);
      printf("\n");
      return;
    }
    
    count++;
    printKthFromEndLL(head->next, k);
  }
}
#endif

void printRevLL(struct node* head)
{
  //if there is a LL, i.e., head isn't NULL
  if (head && head->next)
  {
    printRevLL(head->next);

    printf("%d ", head->data);
  
    #ifdef DLL
      if (!head->prev)
        printf("\n");
    #endif
  }
}

void sortedInsert(struct node** head, struct node* ptr)
{
  struct node* current = *head;

  //insertion at head
  if (*head == NULL || (*head)->data >= ptr->data)
  {
    ptr->next = *head;
    *head = ptr;
  }
  else
  {
    //need a ptr to the node before the point of insertion
    while (current->next && current->next->data < ptr->data)
      current = current->next;

    //setup node
    ptr->next = current->next;
    
    //introduce ptr
    current->next = ptr;
  }
}

void sortLL(struct node** head)
{
  struct node* current = *head, *result = NULL, *next;
    
  while (current)
  {
    //tricky -- note the next ptr before we change it
    next = current->next;
    sortedInsert(&result, current);
    current = next;
  }

  *head = result;
}

int findNum(struct node** head, int data)
{
  struct node* current = *head;

  while (current)
  {
    if (current->data == data)
    {
        printf("[findNum] Node with data %d found\n", data);
        return true;
    }

    current = current->next;
  }

  printf("[findNum] Node with data %d not found\n", data);
  return false;
}

int countOccurencesNum(struct node** head, int data)
{
  struct node* current = *head;
  int count = 0;

  while (current)
  {
    if (current->data == data)
        count++;

    current = current->next;
  }
  
  return count;
}

int main()
{
  struct node* head = NULL;

  //1 -> 2 -> 3 -> 4 -> 5
  pushNode(&head, 1);
  pushNode(&head, 2);
  pushNode(&head, 3);
  pushNode(&head, 4);
  pushNode(&head, 5);
  
  //print LL
  printLL(head);
  
  #ifdef DLL
    //print DLL
    printDLL(head);
  #endif

  //popNode 1
  int data = popNode(&head);
  (data != -1) ? printf("[main] Popped element with data: %d\n", data) : printf("[main] Nothing to pop!\n");

  //popNode 2
  data = popNode(&head);
  (data != -1) ? printf("[main] Popped element with data: %d\n", data) : printf("[main] Nothing to pop!\n");
  
  //print LL
  printLL(head);

  #ifdef DLL
    //print DLL
    printDLL(head);
  #endif  

  printf("[main] Printing linked list in a reverse manner...\n\t");
  printRevLL(head);

  //get length
  getLength(head);
  
  //add node at pos 2
  printf("[main] Printing LL after insertion of a node at position 2...\n");
  addNode(&head, 2, 10);

  //print LL
  printLL(head);

  //add node at pos 4, the end of LL
  addNode(&head, 4, 100);

  //print LL
  printf("[main] Printing LL after insertion of a node at position 4...\n");
  printLL(head);

  #ifdef DLL
    //print DLL
    printDLL(head);
  #endif  

  //remove node at the end of LL
  deleteNode(&head, 4);

  //print LL
  printf("[main] Printing LL after deletion of a node at position 4...\n");
  printLL(head);

  #ifdef DLL
    //print DLL
    printDLL(head);
  #endif  
  
  //print 2nd element from the end
  printf("[main] Printing second element from the end...\n\t");
  printKthFromEndLL(head, 2);
  
  reverseLL(&head);
  
  //print LL
  printLL(head);

  //delete 3rd node
  printf("[main] Deleting the third node...\n");
  deleteNodePtr(&head, head->next->next);
  
  //print LL
  printf("[main] Printing LL after deletion of the third node...\n");
  printLL(head);

  //remove node at the end of LL
  deleteNode(&head, 0);
  
  //print LL
  printf("[main] Printing LL after deletion of the head node...\n");
  printLL(head);  
  
  #ifdef DLL
    //print DLL
    printDLL(head);
  #endif  

  //sort LL
  sortLL(&head);

  //print LL
  printf("[main] Printing sorted LL...\n");
  printLL(head); 

  //find node with data 5
  findNum(&head, 4);

  //find nodes with data 3
  data = 3;
  int count = countOccurencesNum(&head, data);
  (count == 0) ? printf("[main] Node with data %d not found\n", data) : printf("[countOccurencesNum] Node with data %d found %d time(s)\n", data, count);

  //cleanUp
  deleteLL(&head);

  //print LL -- confirm deletion
  printLL(head);

  #ifdef DLL
    //print DLL
    printDLL(head);
  #endif  
}
